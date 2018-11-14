# $NetBSD: Makefile,v 1.50 2018/11/14 22:21:00 kleink Exp $
#

BMP_USE_ESD:=		yes
.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
PKGREVISION=		37
CATEGORIES+=		gnome

COMMENT=		BMP plugin to output sound through the esound daemon

DEPENDS+=		bmp>=0.9.7.1:../../audio/bmp

BUILD_DIRS=		Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
