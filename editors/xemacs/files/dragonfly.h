/* Synched up with: FSF 19.31. */

/* s/ file for DragonFly system.  */

/* Get most of the stuff from bsd4.3 */
#include "bsd4-3.h"

/* For mem-limits.h. */
#define BSD4_2

/* These aren't needed, since we have getloadavg.  */
#undef KERNEL_FILE
#undef LDAV_SYMBOL

#define PENDING_OUTPUT_COUNT(FILE) ((FILE)->_p - (FILE)->_bf._base)

#define INTERRUPTIBLE_OPEN

#define LIBS_DEBUG
#define LIBS_SYSTEM "-lutil"

#ifndef NOT_C_CODE
#ifdef BSD /* fixing BSD define */
#undef BSD
#endif
#include <sys/param.h>
/* Kludge to work around setlocale(LC_ALL,...) not working after 01/1997 */
#endif /* C code */

#define LIBS_TERMCAP "-ltermcap"

#ifndef NOT_C_CODE
#include <stddef.h>
#endif
#define LD_SWITCH_SYSTEM

#ifdef DFLY_CRT_USRLIB
#define ORDINARY_LINK
#else
#define START_FILES pre-crt0.o /usr/lib/gcc41/crt1.o /usr/lib/gcc41/crti.o /usr/lib/gcc41/crtbegin.o
#define LIB_STANDARD -L/usr/lib/gcc41 -lgcc -lc -lgcc /usr/lib/gcc41/crtend.o /usr/lib/gcc41/crtn.o
#endif

#define UNEXEC "unexelf.o"
#define LINKER "$(CC) -nostdlib"
#undef LIB_GCC
#define LIB_GCC

/* #define NO_TERMIO */ /* detected in configure */
#define DECLARE_GETPWUID_WITH_UID_T

/* freebsd uses OXTABS instead of the expected TAB3. */
#define TABDLY OXTABS
#define TAB3 OXTABS

/* Needed to avoid hanging when child process writes an error message
   and exits -- enami tsugutomo <enami@ba2.so-net.or.jp>.  */
#define vfork fork
