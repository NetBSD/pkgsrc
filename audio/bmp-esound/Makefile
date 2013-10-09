# $NetBSD: Makefile,v 1.37 2013/10/09 17:39:04 wiz Exp $
#

BMP_USE_ESD:=		yes
.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
PKGREVISION=		24
CATEGORIES+=		gnome

COMMENT=		BMP plugin to output sound through the esound daemon

DEPENDS+=		bmp>=0.9.7.1:../../audio/bmp

BUILD_DIRS=		Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
