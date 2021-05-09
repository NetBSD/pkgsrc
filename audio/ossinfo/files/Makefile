# $NetBSD: Makefile,v 1.1 2021/05/09 08:27:21 nia Exp $

CFLAGS+=	-DLOCAL_BUILD

OBJS=		ossinfo.o
PROG=		ossinfo

all: ${PROG}

.c.o:
	${CC} ${CFLAGS} -c ${.IMPSRC}

${PROG}: ${OBJS}
	${CC} ${LDFLAGS} -o ${PROG} ${OBJS}
