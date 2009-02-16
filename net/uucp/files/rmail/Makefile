# $NetBSD: Makefile,v 1.4 2009/02/16 13:28:29 joerg Exp $

PROG=	rmail
MAN=	rmail.8
BINDIR=	@PREFIX@/bin
MANDIR=	@PREFIX@/@PKGMANDIR@

SRCS=	rmail.c
OBJS=	rmail.o

all: ${PROG}

install: all
	@INSTALL_PROGRAM@ ${PROG} ${DESTDIR}${BINDIR}/${PROG}
	@INSTALL_MAN@ ${MAN} ${DESTDIR}${MANDIR}/man8

.c.o:
	${CC} ${CPPFLAGS} ${CFLAGS} -c $<

${PROG}: ${OBJS}
	${CC} ${LDFLAGS} -o $@ ${OBJS}
