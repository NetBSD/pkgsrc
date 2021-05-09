# $NetBSD: Makefile,v 1.1 2021/05/09 07:54:42 nia Exp $

GTK_CFLAGS!=	pkg-config --cflags gtk+-2.0
GTK_LIBS!=	pkg-config --libs gtk+-2.0

CFLAGS+=	${GTK_CFLAGS}
LDFLAGS+=	${GTK_LIBS}

OBJS=		gtkvu.o ossxmix.o

all: ossxmix

.c.o:
	${CC} ${CFLAGS} -c ${.IMPSRC}

ossxmix: ${OBJS}
	${CC} ${LDFLAGS} -o ossxmix ${OBJS}
