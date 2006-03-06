# $NetBSD: Makefile,v 1.8 2006/03/06 00:18:14 wiz Exp $
#

.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
PKGREVISION=		3
CATEGORIES+=		gnome

COMMENT=		BMP plugin to output sound through the esound daemon

DEPENDS+=		bmp>=0.9.7:../../audio/bmp

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-esd/--enable-esd/}

BUILD_DIRS=		${WRKSRC}/Output/esd
INSTALL_DIRS=		${WRKSRC}/Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
