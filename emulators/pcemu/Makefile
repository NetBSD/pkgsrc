# $NetBSD: Makefile,v 1.14 2007/12/01 23:57:23 wiz Exp $

DISTNAME=	pcemu1.01alpha
PKGNAME=	pcemu-1.01a
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	eric@fox.phoenix.az.us
COMMENT=	8086 PC emulator, by David Hedley

USE_TOOLS+=	bdftopcf mkfontdir

MAKE_ENV+=	FILESDIR=${FILESDIR:Q}

FONTS_DIRS.x11=	${PREFIX}/lib/pcemu/font
REQD_DIRS=	${PREFIX}/lib/pcemu/font
REQD_DIRS+=	${PREFIX}/lib/pcemu

do-configure:
	cd ${WRKSRC};							\
		${MKDIR} ${WRKSRC}/bootstrap;				\
		${SH} < ${FILESDIR}/bootstrap.shar

post-configure:
	${SED} -e 's|/usr/local|${PREFIX}|g' < ${WRKSRC}/bootstrap/help.txt > \
		${WRKSRC}/foo
	${MV} ${WRKSRC}/foo ${WRKSRC}/bootstrap/help.txt

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
