# $NetBSD: Makefile,v 1.1.1.1 2013/02/23 21:11:56 agc Exp $

SRCS=src/netpgpverify/main.c
OBJS=main.o
LIBS=${PREFIX}/lib/libnetpgpverify.la -lz -lbz2

CFLAGS+=-I${PREFIX}/include

all: netpgpverify

main.o: ${SRCS}
	libtool --mode=compile ${CC} ${CFLAGS} -c ${SRCS} -o ${OBJS}
	
netpgpverify: ${OBJS}
	libtool --mode=link ${CC} ${LDFLAGS} ${OBJS} ${LIBS} -o netpgpverify

