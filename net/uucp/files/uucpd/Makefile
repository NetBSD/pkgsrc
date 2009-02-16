# $NetBSD: Makefile,v 1.4 2009/02/16 13:28:29 joerg Exp $

PROG=		uucpd
MAN=		uucpd.8
BINDIR=		@PREFIX@/libexec
MANDIR=		@PREFIX@/@PKGMANDIR@
CPPFLAGS+=	@UUCPD_CPPFLAGS@
LIBS+=		@UUCPD_LIBS@

SRCS=		uucpd.c
OBJS=		uucpd.o

all: ${PROG}

install: all
	@INSTALL_PROGRAM@ ${PROG} ${DESTDIR}${BINDIR}/${PROG}
	@INSTALL_MAN@ ${MAN} ${DESTDIR}${MANDIR}/man8

.c.o:
	${CC} ${CPPFLAGS} ${CFLAGS} -c $<

${PROG}: ${OBJS}
	${CC} ${LDFLAGS} -o $@ ${OBJS} ${LIBS}
