# $NetBSD: Makefile,v 1.18 2011/05/24 12:03:37 obache Exp $
#

DISTNAME=	xbomber.0.8
PKGNAME=	xbomber-0.8
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/xbomber/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/xbomber/
COMMENT=	Colorful game where you blow other people/robots up

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xbomber
MAKE_FILE=	makefile

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xbomber
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/xbomber

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
