# $NetBSD: Makefile,v 1.46 2018/01/28 20:10:40 wiz Exp $
#

BMP_USE_ESD:=		yes
.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
PKGREVISION=		33
CATEGORIES+=		gnome

COMMENT=		BMP plugin to output sound through the esound daemon

DEPENDS+=		bmp>=0.9.7.1:../../audio/bmp

BUILD_DIRS=		Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
