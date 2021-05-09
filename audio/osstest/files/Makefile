# $NetBSD: Makefile,v 1.1 2021/05/09 08:14:52 nia Exp $

CFLAGS+=	-DLOCAL_BUILD

OBJS=		osstest.o help.o wavedata.o
PROG=		osstest

all: ${PROG}

.c.o:
	${CC} ${CFLAGS} -c ${.IMPSRC}

${PROG}: ${OBJS}
	${CC} ${LDFLAGS} -o ${PROG} ${OBJS}
