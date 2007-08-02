# $NetBSD: Makefile,v 1.2 2007/08/02 15:07:27 joerg Exp $
#
# Replacement Makefile for zlib.
#

OBJS=	adler32.o compress.o crc32.o deflate.o gzio.o \
	infback.o inffast.o inflate.o inftrees.o trees.o \
	uncompr.o zutil.o
LOBJS=	${OBJS:R:S/$/.lo/g}

all: libz.la

libz.la: ${LOBJS}
	${LIBTOOL} --mode=link ${CC} ${LDFLAGS} ${CFLAGS} -o ${.TARGET} \
	    ${LOBJS} -version-info 1:2 -rpath ${PREFIX}/lib

libz.a: ${OBJS}
	${AR} cq ${.TARGET} ${OBJS}
	${RANLIB} ${.TARGET}

.SUFFIXES: .c .o .lo

.c.o:
	${CC} -c ${CFLAGS} -o ${.TARGET} ${.IMPSRC}

.c.lo:
	${LIBTOOL} --mode=compile ${CC} -c ${CFLAGS} -o ${.TARGET} ${.IMPSRC}
