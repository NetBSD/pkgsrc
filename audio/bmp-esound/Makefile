# $NetBSD: Makefile,v 1.10 2006/05/31 09:12:18 rillig Exp $
#

BMP_USE_ESD:=		yes
.include "../../audio/bmp/Makefile.common"

PKGNAME=		${DISTNAME:S/bmp/bmp-esound/}
PKGREVISION=		4
CATEGORIES+=		gnome

COMMENT=		BMP plugin to output sound through the esound daemon

DEPENDS+=		bmp>=0.9.7:../../audio/bmp

BUILD_DIRS=		Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
