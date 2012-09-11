# $NetBSD: Makefile,v 1.28 2012/09/11 23:59:26 asau Exp $
#

BMP_USE_ESD:=		yes
.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
PKGREVISION=		15
CATEGORIES+=		gnome

COMMENT=		BMP plugin to output sound through the esound daemon

DEPENDS+=		bmp>=0.9.7.1:../../audio/bmp

BUILD_DIRS=		Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
