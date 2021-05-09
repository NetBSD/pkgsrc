# $NetBSD: Makefile,v 1.1 2021/05/09 09:06:58 nia Exp $

CFLAGS+=	-DLOCAL_BUILD

OBJS=		ossplay.o ossplay_console.o ossplay_decode.o
OBJS+=		ossplay_parser.o ossplay_wparser.o

PROG=		ossplay

all: ${PROG}

.c.o:
	${CC} ${CFLAGS} -c ${.IMPSRC}

${PROG}: ${OBJS}
	${CC} ${LDFLAGS} -o ${PROG} ${OBJS}
