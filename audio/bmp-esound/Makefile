# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:05 joerg Exp $
#

.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
PKGREVISION=		2
CATEGORIES+=		gnome

COMMENT=		BMP plugin to output sound through the esound daemon

DEPENDS+=		bmp>=0.9.7:../../audio/bmp

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-esd/--enable-esd/}

BUILD_DIRS=		${WRKSRC}/Output/esd
INSTALL_DIRS=		${WRKSRC}/Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
