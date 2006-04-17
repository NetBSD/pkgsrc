# $NetBSD: Makefile,v 1.9 2006/04/17 14:52:10 wiz Exp $
#

.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
PKGREVISION=		4
CATEGORIES+=		gnome

COMMENT=		BMP plugin to output sound through the esound daemon

DEPENDS+=		bmp>=0.9.7:../../audio/bmp

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-esd/--enable-esd/}

BUILD_DIRS=		${WRKSRC}/Output/esd
INSTALL_DIRS=		${WRKSRC}/Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
