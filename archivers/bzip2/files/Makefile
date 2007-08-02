# $NetBSD: Makefile,v 1.1 2007/08/02 13:04:42 joerg Exp $
#
# Replacement Makefile for bzip2.
#

OBJS=	blocksort.o bzlib.o compress.o crctable.o \
	decompress.o huffman.o randtable.o
LOBJS=	${OBJS:R:S/$/.lo/g}

all: libbz2.la bzip2 bzip2recover

libbz2.la: ${LOBJS}
	${LIBTOOL} --mode=link ${CC} ${LDFLAGS} ${CFLAGS} -o ${.TARGET} \
	    ${LOBJS} -version-info 0:0 -rpath ${PREFIX}/lib

libbz2.a: ${OBJS}
	${AR} cq ${.TARGET} ${OBJS}
	${RANLIB} ${.TARGET}

bzip2: libbz2.a bzip2.o
	${LIBTOOL} --mode=link ${CC} ${LDFLAGS} ${CFLAGS} -o ${.TARGET} \
	    bzip2.o libbz2.la
bzip2recover: bzip2recover.o
	${CC} ${LDFLAGS} ${CFLAGS} -o ${.TARGET} bzip2recover.o

.SUFFIXES: .c .o .lo

.c.o:
	${CC} -c ${CFLAGS} -o ${.TARGET} ${.IMPSRC}

.c.lo:
	${LIBTOOL} --mode=compile ${CC} -c ${CFLAGS} -o ${.TARGET} ${.IMPSRC}
