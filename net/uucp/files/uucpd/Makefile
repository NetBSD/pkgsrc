# $NetBSD: Makefile,v 1.3 2007/06/18 14:45:29 jlam Exp $

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
	@INSTALL_PROGRAM@ ${PROG} ${BINDIR}/${PROG}
	@INSTALL_MAN@ ${MAN} ${MANDIR}/man8

.c.o:
	${CC} ${CPPFLAGS} ${CFLAGS} -c $<

${PROG}: ${OBJS}
	${CC} ${LDFLAGS} -o $@ ${OBJS} ${LIBS}
