#	Original NetBSD: Makefile,v 1.13 1999/07/09 07:07:13 garbled Exp

# libtool-using Makefile for libz, derived deom bsd.mk for Solaris - HF

LIB=	z
MKMAN=	no

SRCS=	adler32.c compress.c crc32.c deflate.c gzio.c infblock.c \
	infcodes.c inffast.c inflate.c inftrees.c infutil.c trees.c uncompr.c \
	zutil.c

CPPFLAGS+= -I${.CURDIR}

CLEANFILES+= minigzip

INCS=	zconf.h zlib.h
INCSDIR=${PREFIX}/include
LIBDIR=${PREFIX}/lib

SHLIB_MAJOR= 0
SHLIB_MINOR= 1

test: minigzip
	echo hello world | ./minigzip | ./minigzip -d

# Note: CFLAGS ommitted by intention!
# This is to verify that zlib.h works standalone.
minigzip : minigzip.c libz.la
	${LIBTOOL} $(CC) -o minigzip ${.CURDIR}/minigzip.c libz.la



all: minigzip

.SUFFIXES: .lo .c
.c.lo:
	${LIBTOOL} ${CC} -c $*.c
lib${LIB}.la: ${SRCS:.c=.lo}
	${LIBTOOL} ${CC} -o lib${LIB}.la ${SRCS:.c=.lo} \
		-rpath ${LIBDIR} \
		-version-info ${SHLIB_MAJOR}:${SHLIB_MINOR}
install:
	${BSD_INSTALL_DATA_DIR} ${INCSDIR}
	${BSD_INSTALL_DATA} zconf.h zlib.h ${INCSDIR}
	${LIBTOOL} ${BSD_INSTALL_DATA} libz.la ${LIBDIR}

