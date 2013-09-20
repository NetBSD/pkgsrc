# $NetBSD: Makefile,v 1.4 2013/09/20 04:05:13 joerg Exp $
#
# Replacement Makefile for bzip2.
#

OBJS=	blocksort.o bzlib.o compress.o crctable.o \
	decompress.o huffman.o randtable.o
LOBJS=	${OBJS:R:S/$/.lo/g}

CFLAGS+=		-D_LARGEFILE_SOURCE -D_LARGE_FILES
CFLAGS+=		-D_FILE_OFFSET_BITS=64

all: libbz2.la bzip2 bzip2recover

libbz2.la: ${LOBJS}
	${LIBTOOL} --tag=CC --mode=link ${CC} ${LDFLAGS} ${CFLAGS} -o ${.TARGET} \
	    ${LOBJS} -version-info 0:0 -rpath ${PREFIX}/lib -no-undefined

libbz2.a: ${OBJS}
	${AR} cq ${.TARGET} ${OBJS}
	${RANLIB} ${.TARGET}

bzip2: libbz2.a bzip2.o
	${LIBTOOL} --tag=CC --mode=link ${CC} ${LDFLAGS} ${CFLAGS} -o ${.TARGET} \
	    bzip2.o libbz2.la
bzip2recover: bzip2recover.o
	${CC} ${LDFLAGS} ${CFLAGS} -o ${.TARGET} bzip2recover.o

.SUFFIXES: .c .o .lo

.c.o:
	${CC} -c ${CFLAGS} -o ${.TARGET} ${.IMPSRC}

.c.lo:
	${LIBTOOL} --tag=CC --mode=compile ${CC} -c ${CFLAGS} -o ${.TARGET} ${.IMPSRC}
