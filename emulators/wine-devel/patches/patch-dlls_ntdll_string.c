$NetBSD: patch-dlls_ntdll_string.c,v 1.1 2016/01/11 22:53:48 joerg Exp $

From https://github.com/wine-mirror/wine/commit/476d97b0eea4ad231e4341add5fcc4b419

--- dlls/ntdll/string.c.orig	2015-02-07 08:14:10.000000000 +0000
+++ dlls/ntdll/string.c
@@ -24,6 +24,7 @@
 #include "wine/port.h"
 
 #include <ctype.h>
+#include <limits.h>
 #include <stdarg.h>
 #include <stdlib.h>
 #include <stdio.h>
@@ -774,16 +775,601 @@ LONG __cdecl NTDLL_atol( const char *npt
 }
 
 
+/* helper function for *scanf.  Returns the value of character c in the
+ * given base, or -1 if the given character is not a digit of the base.
+ */
+static int char2digit( char c, int base )
+{
+    if ((c >= '0' && c <= '9') && (c <= '0'+base-1)) return (c-'0');
+    if (base <= 10) return -1;
+    if ((c >= 'A') && (c <= 'Z') && (c <= 'A'+base-11)) return (c-'A'+10);
+    if ((c >= 'a') && (c <= 'z') && (c <= 'a'+base-11)) return (c-'a'+10);
+    return -1;
+}
+
+
+static int NTDLL_vsscanf( const char *str, const char *format, __ms_va_list ap)
+{
+    int rd = 0, consumed = 0;
+    int nch;
+    if (!*format) return 0;
+
+    nch = (consumed++, *str++);
+    if (nch == '\0')
+        return EOF;
+
+    while (*format)
+    {
+        if (isspace( *format ))
+        {
+            /* skip whitespace */
+            while ((nch != '\0') && isspace( nch ))
+                nch = (consumed++, *str++);
+        }
+        else if (*format == '%')
+        {
+            int st = 0;
+            BOOLEAN suppress = 0;
+            int width = 0;
+            int base;
+            int h_prefix = 0;
+            BOOLEAN l_prefix = FALSE;
+            BOOLEAN L_prefix = FALSE;
+            BOOLEAN w_prefix = FALSE;
+            BOOLEAN I64_prefix = FALSE;
+            BOOLEAN prefix_finished = FALSE;
+            format++;
+            /* a leading asterisk means 'suppress assignment of this field' */
+            if (*format == '*')
+            {
+                format++;
+                suppress = TRUE;
+            }
+            /* look for width specification */
+            while (isdigit( *format ))
+            {
+                width *= 10;
+                width += *format++ - '0';
+            }
+            if (width == 0) width = -1; /* no width spec seen */
+            /* read prefix (if any) */
+            while (!prefix_finished)
+            {
+                switch (*format)
+                {
+                case 'h': h_prefix++; break;
+                case 'l':
+                    if (*(format+1) == 'l')
+                    {
+                        I64_prefix = TRUE;
+                        format++;
+                    }
+                    l_prefix = TRUE;
+                    break;
+                case 'w': w_prefix = TRUE; break;
+                case 'L': L_prefix = TRUE; break;
+                case 'I':
+                    if (*(format + 1) == '6' &&
+                        *(format + 2) == '4')
+                    {
+                        I64_prefix = TRUE;
+                        format += 2;
+                    }
+                    break;
+                default:
+                    prefix_finished = TRUE;
+                }
+                if (!prefix_finished) format++;
+            }
+            /* read type */
+            switch (*format)
+            {
+            case 'p':
+            case 'P': /* pointer. */
+                if (sizeof(void *) == sizeof(LONGLONG)) I64_prefix = TRUE;
+                /* fall through */
+            case 'x':
+            case 'X': /* hexadecimal integer. */
+                base = 16;
+                goto number;
+            case 'o': /* octal integer */
+                base = 8;
+                goto number;
+            case 'u': /* unsigned decimal integer */
+                base = 10;
+                goto number;
+            case 'd': /* signed decimal integer */
+                base = 10;
+                goto number;
+            case 'i': /* generic integer */
+                base = 0;
+            number:
+                {
+                    /* read an integer */
+                    ULONGLONG cur = 0;
+                    BOOLEAN negative = FALSE;
+                    BOOLEAN seendigit = FALSE;
+                    /* skip initial whitespace */
+                    while ((nch != '\0') && isspace( nch ))
+                        nch = (consumed++, *str++);
+                    /* get sign */
+                    if (nch == '-' || nch == '+')
+                    {
+                        negative = (nch == '-');
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                    }
+                    /* look for leading indication of base */
+                    if (width != 0 && nch == '0' && *format != 'p' && *format != 'P')
+                    {
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                        seendigit = TRUE;
+                        if (width != 0 && (nch == 'x' || nch == 'X'))
+                        {
+                            if (base == 0)
+                                base = 16;
+                            if (base == 16)
+                            {
+                                nch = (consumed++, *str++);
+                                if (width > 0) width--;
+                                seendigit = FALSE;
+                            }
+                        } else if (base == 0)
+                            base = 8;
+                    }
+                    /* format %i without indication of base */
+                    if (base == 0)
+                        base = 10;
+                    /* throw away leading zeros */
+                    while (width != 0 && nch == '0')
+                    {
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                        seendigit = TRUE;
+                    }
+                    if (width != 0 && char2digit( nch, base ) != -1)
+                    {
+                        cur = char2digit( nch, base );
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                        seendigit = TRUE;
+                    }
+                    /* read until no more digits */
+                    while (width != 0 && nch != '\0' && char2digit( nch, base ) != -1)
+                    {
+                        cur = cur*base + char2digit( nch, base );
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                        seendigit = TRUE;
+                    }
+                    /* okay, done! */
+                    if (!seendigit) break; /* not a valid number */
+                    st = 1;
+                    if (!suppress)
+                    {
+#define _SET_NUMBER_( type ) *va_arg( ap, type* ) = negative ? -cur : cur
+                        if (I64_prefix) _SET_NUMBER_( LONGLONG );
+                        else if (l_prefix) _SET_NUMBER_( LONG );
+                        else if (h_prefix == 1) _SET_NUMBER_( short int );
+                        else _SET_NUMBER_( int );
+                    }
+                }
+                break;
+            case 'e':
+            case 'E':
+            case 'f':
+            case 'g':
+            case 'G':
+                { /* read a float */
+                    long double cur = 1, expcnt = 10;
+                    ULONGLONG d, hlp;
+                    int exp = 0;
+                    BOOLEAN negative = FALSE;
+                    /*unsigned fpcontrol;*/
+                    BOOLEAN negexp;
+
+                    /* skip initial whitespace */
+                    while (nch != '\0' && isspace( nch ))
+                        nch = (consumed++, *str++);
+
+                    /* get sign */
+                    if (nch == '-' || nch == '+')
+                    {
+                        negative = (nch == '-');
+                        if (width > 0) width--;
+                        if (width == 0) break;
+                        nch = (consumed++, *str++);
+                    }
+
+                    /* get first digit */
+                    if ('.' != nch)
+                    {
+                        if (!isdigit( nch )) break;
+                        d = nch - '0';
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                        /* read until no more digits */
+                        while (width != 0 && nch != '\0' && isdigit( nch ))
+                        {
+                            hlp = d * 10 + nch - '0';
+                            nch = (consumed++, *str++);
+                            if (width > 0) width--;
+                            if(d > (ULONGLONG)-1/10 || hlp < d)
+                            {
+                                exp++;
+                                break;
+                            }
+                            else
+                                d = hlp;
+                        }
+                        while (width != 0 && nch != '\0' && isdigit( nch ))
+                        {
+                            exp++;
+                            nch = (consumed++, *str++);
+                            if (width > 0) width--;
+                        }
+                    }
+                    else
+                        d = 0; /* Fix: .8 -> 0.8 */
+
+                    /* handle decimals */
+                    if (width != 0 && nch == '.')
+                    {
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+
+                        while (width != 0 && nch != '\0' && isdigit( nch ))
+                        {
+                            hlp = d * 10 + nch - '0';
+                            nch = (consumed++, *str++);
+                            if (width > 0) width--;
+                            if(d > (ULONGLONG)-1/10 || hlp < d)
+                                break;
+
+                            d = hlp;
+                            exp--;
+                        }
+                        while (width != 0 && nch != '\0' && isdigit( nch ))
+                        {
+                            nch = (consumed++, *str++);
+                            if (width > 0) width--;
+                        }
+                    }
+
+                    /* handle exponent */
+                    if (width != 0 && (nch == 'e' || nch == 'E'))
+                    {
+                        int sign = 1, e = 0;
+
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                        if (width != 0 && (nch == '+' || nch == '-'))
+                        {
+                            if(nch == '-')
+                                sign = -1;
+                            nch = (consumed++, *str++);
+                            if (width > 0) width--;
+                        }
+
+                        /* exponent digits */
+                        while (width != 0 && nch != '\0' && isdigit( nch ))
+                        {
+                            if (e > INT_MAX/10 || (e = e * 10 + nch - '0') < 0)
+                                e = INT_MAX;
+                            nch = (consumed++, *str++);
+                            if (width > 0) width--;
+                        }
+                        e *= sign;
+
+                        if(exp < 0 && e < 0 && e+exp > 0) exp = INT_MIN;
+                        else if(exp > 0 && e > 0 && e+exp < 0) exp = INT_MAX;
+                        else exp += e;
+                    }
+
+                    /*fpcontrol = _control87(0, 0);
+                    _control87(MSVCRT__EM_DENORMAL|MSVCRT__EM_INVALID|MSVCRT__EM_ZERODIVIDE
+                            |MSVCRT__EM_OVERFLOW|MSVCRT__EM_UNDERFLOW|MSVCRT__EM_INEXACT, 0xffffffff);*/
+
+                    negexp = (exp < 0);
+                    if (negexp)
+                        exp = -exp;
+                    /* update 'cur' with this exponent. */
+                    while (exp)
+                    {
+                        if(exp & 1)
+                            cur *= expcnt;
+                        exp /= 2;
+                        expcnt = expcnt*expcnt;
+                    }
+                    cur = (negexp ? d/cur : d*cur);
+
+                    /*_control87(fpcontrol, 0xffffffff);*/
+
+                    st = 1;
+                    if (!suppress)
+                    {
+                        if (L_prefix || l_prefix) _SET_NUMBER_( double );
+                        else _SET_NUMBER_( float );
+                    }
+                }
+                break;
+                /* According to msdn,
+                 * 's' reads a character string in a call to fscanf
+                 * and 'S' a wide character string and vice versa in a
+                 * call to fwscanf. The 'h', 'w' and 'l' prefixes override
+                 * this behaviour. 'h' forces reading char * but 'l' and 'w'
+                 * force reading WCHAR. */
+            case 's':
+                if (w_prefix || l_prefix) goto widecharstring;
+                else if (h_prefix) goto charstring;
+                else goto charstring;
+            case 'S':
+                if (w_prefix || l_prefix) goto widecharstring;
+                else if (h_prefix) goto charstring;
+                else goto widecharstring;
+            charstring:
+                { /* read a word into a char */
+                    char *sptr = suppress ? NULL : va_arg( ap, char * );
+                    char *sptr_beg = sptr;
+                    unsigned size = UINT_MAX;
+                    /* skip initial whitespace */
+                    while (nch != '\0' && isspace( nch ))
+                        nch = (consumed++, *str++);
+                    /* read until whitespace */
+                    while (width != 0 && nch != '\0' && !isspace( nch ))
+                    {
+                        if (!suppress)
+                        {
+                            *sptr++ = nch;
+                            if(size > 1) size--;
+                            else
+                            {
+                                *sptr_beg = 0;
+                                return rd;
+                            }
+                        }
+                        st++;
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                    }
+                    /* terminate */
+                    if (st && !suppress) *sptr = 0;
+                }
+                break;
+            widecharstring:
+                { /* read a word into a WCHAR * */
+                    WCHAR *sptr = suppress ? NULL : va_arg( ap, WCHAR * );
+                    WCHAR *sptr_beg = sptr;
+                    unsigned size = UINT_MAX;
+                    /* skip initial whitespace */
+                    while (nch != '\0' && isspace( nch ))
+                        nch = (consumed++, *str++);
+                    /* read until whitespace */
+                    while (width != 0 && nch != '\0' && !isspace( nch ))
+                    {
+                        if (!suppress)
+                        {
+                            *sptr++ = nch;
+                            if (size > 1) size--;
+                            else
+                            {
+                                *sptr_beg = 0;
+                                return rd;
+                            }
+                        }
+                        st++;
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                    }
+                    /* terminate */
+                    if (st && !suppress) *sptr = 0;
+                }
+                break;
+            /* 'c' and 'C work analogously to 's' and 'S' as described
+             * above */
+            case 'c':
+                if (w_prefix || l_prefix) goto widecharacter;
+                else if (h_prefix) goto character;
+                else goto character;
+            case 'C':
+                if (w_prefix || l_prefix) goto widecharacter;
+                else if (h_prefix) goto character;
+                else goto widecharacter;
+            character:
+                { /* read single character into char */
+                    char *str = suppress ? NULL : va_arg( ap, char * );
+                    char *pstr = str;
+                    unsigned size = UINT_MAX;
+                    if (width == -1) width = 1;
+                    while (width && nch != '\0')
+                    {
+                        if (!suppress)
+                        {
+                            *str++ = nch;
+                            if(size) size--;
+                            else
+                            {
+                                *pstr = 0;
+                                return rd;
+                            }
+                        }
+                        st++;
+                        width--;
+                        nch = (consumed++, *str++);
+                    }
+                }
+                break;
+            widecharacter:
+                { /* read single character into a WCHAR */
+                    WCHAR *str = suppress ? NULL : va_arg( ap, WCHAR * );
+                    WCHAR *pstr = str;
+                    unsigned size = UINT_MAX;
+                    if (width == -1) width = 1;
+                    while (width && nch != '\0')
+                    {
+                        if (!suppress)
+                        {
+                            *str++ = nch;
+                            if (size) size--;
+                            else
+                            {
+                                *pstr = 0;
+                                return rd;
+                            }
+                        }
+                        st++;
+                        width--;
+                        nch = (consumed++, *str++);
+                    }
+                }
+                break;
+            case 'n':
+                {
+                    if (!suppress)
+                    {
+                        int *n = va_arg( ap, int * );
+                        *n = consumed - 1;
+                    }
+                    /* This is an odd one: according to the standard,
+                     * "Execution of a %n directive does not increment the
+                     * assignment count returned at the completion of
+                     * execution" even if it wasn't suppressed with the
+                     * '*' flag.  The Corrigendum to the standard seems
+                     * to contradict this (comment out the assignment to
+                     * suppress below if you want to implement these
+                     * alternate semantics) but the windows program I'm
+                     * looking at expects the behavior I've coded here
+                     * (which happens to be what glibc does as well).
+                     */
+                    suppress = TRUE;
+                    st = 1;
+                }
+                break;
+            case '[':
+                {
+                    char *str = suppress ? NULL : va_arg( ap, char * );
+                    char *sptr = str;
+                    RTL_BITMAP bitMask;
+                    ULONG Mask[8];
+                    BOOLEAN invert = FALSE; /* Set if we are NOT to find the chars */
+                    unsigned size = UINT_MAX;
+
+                    RtlInitializeBitMap( &bitMask, Mask, sizeof(Mask) * 8 );
+
+                    /* Read the format */
+                    format++;
+                    if (*format == '^')
+                    {
+                        invert = TRUE;
+                        format++;
+                    }
+                    if (*format == ']')
+                    {
+                        RtlSetBits( &bitMask, ']', 1 );
+                        format++;
+                    }
+                    while (*format && (*format != ']'))
+                    {
+                        /* According to msdn:
+                         * "Note that %[a-z] and %[z-a] are interpreted as equivalent to %[abcde...z]." */
+                        if ((*format == '-') && (*(format + 1) != ']'))
+                        {
+                            if ((*(format - 1)) < *(format + 1))
+                                RtlSetBits( &bitMask, *(format - 1) +1 , *(format + 1) - *(format - 1) );
+                            else
+                                RtlSetBits( &bitMask, *(format + 1)    , *(format - 1) - *(format + 1) );
+                            format++;
+                        }
+                        else
+                            RtlSetBits( &bitMask, *format, 1 );
+                        format++;
+                    }
+                    /* read until char is not suitable */
+                    while (width != 0 && nch != '\0')
+                    {
+                        if (!invert)
+                        {
+                            if(RtlAreBitsSet( &bitMask, nch, 1 ))
+                            {
+                                if (!suppress) *sptr++ = nch;
+                            }
+                            else
+                                break;
+                        }
+                        else
+                        {
+                            if (RtlAreBitsClear( &bitMask, nch, 1 ))
+                            {
+                                if (!suppress) *sptr++ = nch;
+                            }
+                            else
+                                break;
+                        }
+                        st++;
+                        nch = (consumed++, *str++);
+                        if (width > 0) width--;
+                        if(size > 1) size--;
+                        else
+                        {
+                            *str = 0;
+                            return rd;
+                        }
+                    }
+                    /* terminate */
+                    if (!suppress) *sptr = 0;
+                }
+                break;
+            default:
+                /* From spec: "if a percent sign is followed by a character
+                 * that has no meaning as a format-control character, that
+                 * character and the following characters are treated as
+                 * an ordinary sequence of characters, that is, a sequence
+                 * of characters that must match the input.  For example,
+                 * to specify that a percent-sign character is to be input,
+                 * use %%." */
+                while (nch != '\0' && isspace( nch ))
+                    nch = (consumed++, *str++);
+                if (nch == *format)
+                {
+                    suppress = TRUE; /* whoops no field to be read */
+                    st = 1; /* but we got what we expected */
+                    nch = (consumed++, *str++);
+                }
+                break;
+            }
+            if (st && !suppress) rd++;
+            else if (!st) break;
+        }
+        /* A non-white-space character causes scanf to read, but not store,
+         * a matching non-white-space character. */
+        else
+        {
+            if (nch == *format)
+                nch = (consumed++, *str++);
+            else break;
+        }
+        format++;
+    }
+    if (nch != '\0')
+    {
+        consumed--, str--;
+    }
+
+    return rd;
+}
+
+
 /*********************************************************************
  *                  sscanf   (NTDLL.@)
  */
 int __cdecl NTDLL_sscanf( const char *str, const char *format, ... )
 {
     int ret;
-    va_list valist;
-    va_start( valist, format );
-    ret = vsscanf( str, format, valist );
-    va_end( valist );
+    __ms_va_list valist;
+    __ms_va_start( valist, format );
+    ret = NTDLL_vsscanf( str, format, valist );
+    __ms_va_end( valist );
     return ret;
 }
 
