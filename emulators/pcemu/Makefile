# $NetBSD: Makefile,v 1.4 2005/03/24 21:12:54 wiz Exp $

DISTNAME=	pcemu1.01alpha
PKGNAME=	pcemu-1.01a
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/ \
		ftp://ftp.interface-business.de/pub/outgoing/ \
		ftp://ftp.cs.bris.ac.uk/pub/users/hedley/

MAINTAINER=	eric@fox.phoenix.az.us
COMMENT=	8086 PC emulator, by David Hedley

USE_X11=	yes
MAKE_ENV+=	FILESDIR=${FILESDIR}

do-configure:
	cd ${WRKSRC};							\
		${MKDIR} ${WRKSRC}/bootstrap;				\
		sh < ${FILESDIR}/bootstrap.shar

post-configure:
	${SED} -e 's|/usr/local|${PREFIX}|g' < ${WRKSRC}/bootstrap/help.txt > \
		${WRKSRC}/foo
	${MV} ${WRKSRC}/foo ${WRKSRC}/bootstrap/help.txt

.include "../../mk/bsd.pkg.mk"
