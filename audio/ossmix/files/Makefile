# $NetBSD: Makefile,v 1.1 2021/05/09 08:02:03 nia Exp $

CFLAGS+=	-DLOCAL_BUILD

OBJS=		ossmix.o
PROG=		ossmix

all: ${PROG}

.c.o:
	${CC} ${CFLAGS} -c ${.IMPSRC}

${PROG}: ${OBJS}
	${CC} ${LDFLAGS} -o ${PROG} ${OBJS}
