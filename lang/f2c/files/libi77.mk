LIB=	I77
SHLIB_MAJOR=	0
SHLIB_MINOR=	0

# Simulate "bsd.init.mk" because pkgsrc doesn't provide it for some reason:
.if !target(__initialized__)
__initialized__:
.if exists(${.CURDIR}/../Makefile.inc)
.include "${.CURDIR}/../Makefile.inc"
.endif
.include <bsd.own.mk>
.include <bsd.obj.mk>
.include <bsd.depall.mk>
.MAIN:		all
.endif
# .include <bsd.init.mk>
.PATH:	$(LIBF2CSRCDIR)

SRCS =	backspac.c close.c dfe.c dolio.c due.c endfile.c err.c \
	fmt.c fmtlib.c ftell_.c iio.c ilnw.c inquire.c lread.c lwrite.c \
	open.c rdfmt.c rewind.c rsfe.c rsli.c rsne.c sfe.c sue.c typesize.c \
	uio.c util.c wref.c wrtfmt.c wsfe.c wsle.c wsne.c xwsne.c
SRCS+=	i77vers.c	# previously known as "Version.c"
# Previously there was "backspace.c" instead of "backspac.c".

DPSRCS=		f2c.h sysdep1.h

CPPFLAGS=	-I.	# for generated include files

f2c.h:	f2c.h0;		cp $> $@
sysdep1.h: sysdep1.h0;	cp $> $@

CLEANFILES=	$(DPSRCS)

CPPFLAGS+=	-DNO_My_ctype
CPPFLAGS+=	-DSkip_f2c_Undefs

i77vers.lo: i77vers.c
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) -c $(.ALLSRC:M*.c)

.if defined(MKLTARCHIVE) && !empty(MKLTARCHIVE:M[Yy][Ee][Ss])
.include "../libtool.mk"
.else
.include "bsd.lib.mk"
.endif
