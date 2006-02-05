# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:02 joerg Exp $

DISTNAME=	pcemu1.01alpha
PKGNAME=	pcemu-1.01a
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/ \
		ftp://ftp.interface-business.de/pub/outgoing/ \
		ftp://ftp.cs.bris.ac.uk/pub/users/hedley/

MAINTAINER=	eric@fox.phoenix.az.us
COMMENT=	8086 PC emulator, by David Hedley

USE_TOOLS+=	bdftopcf mkfontdir

BROKEN_IN=	pkgsrc-2005Q4

MAKE_ENV+=	FILESDIR=${FILESDIR:Q}

.include "../../mk/x11.buildlink3.mk"

do-configure:
	cd ${WRKSRC};							\
		${MKDIR} ${WRKSRC}/bootstrap;				\
		${SH} < ${FILESDIR}/bootstrap.shar

post-configure:
	${SED} -e 's|/usr/local|${PREFIX}|g' < ${WRKSRC}/bootstrap/help.txt > \
		${WRKSRC}/foo
	${MV} ${WRKSRC}/foo ${WRKSRC}/bootstrap/help.txt

.include "../../mk/bsd.pkg.mk"
