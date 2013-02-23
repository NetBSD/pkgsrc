# $NetBSD: Makefile,v 1.1.1.1 2013/02/23 21:04:26 agc Exp $

# Makefile for libnetpgpverify
SRCS=libverify.c b64.c pgpsum.c
SRCS+=digest.c tiger.c
SRCS+=bignum.c misc.c

CFLAGS+=-I${EXTDIST}/src/libbn
CFLAGS+=-I${EXTDIST}/src/libdigest
CFLAGS+=-I${EXTDIST}/src/librsa

OBJS=libverify.o b64.o pgpsum.o
OBJS+=digest.o tiger.o
OBJS+=bignum.o misc.o

EXTDIST=${.CURDIR}
.PATH: ${EXTDIST}/src/libverify ${EXTDIST}/src/libdigest ${EXTDIST}/src/libbn ${EXTDIST}/src/librsa

INCS=verify.h
INCSDIR=${PREFIX}/include/netpgp

libverify.o: src/libverify/libverify.c
	libtool --mode=compile --tag=CC ${CC} ${CFLAGS} -c  src/libverify/libverify.c
b64.o: src/libverify/b64.c
	libtool --mode=compile --tag=CC ${CC} ${CFLAGS} -c  src/libverify/b64.c
pgpsum.o: src/libverify/pgpsum.c
	libtool --mode=compile --tag=CC ${CC} ${CFLAGS} -c  src/libverify/pgpsum.c
digest.o: src/libdigest/digest.c
	libtool --mode=compile --tag=CC ${CC} ${CFLAGS} -c  src/libdigest/digest.c
tiger.o: src/libdigest/tiger.c
	libtool --mode=compile --tag=CC ${CC} ${CFLAGS} -c  src/libdigest/tiger.c
bignum.o: src/libbn/bignum.c
	libtool --mode=compile --tag=CC ${CC} ${CFLAGS} -c  src/libbn/bignum.c
misc.o: src/libbn/misc.c
	libtool --mode=compile --tag=CC ${CC} ${CFLAGS} -c  src/libbn/misc.c

libnetpgpverify.a: ${OBJS}
	libtool --mode=link --tag=CC cc -o ${.TARGET:.a=.la} ${OBJS:.o=.lo} -rpath ${PREFIX}/lib -version-info 0:0

all: libnetpgpverify.a
