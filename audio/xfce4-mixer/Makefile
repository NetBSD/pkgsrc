# $NetBSD: Makefile,v 1.14 2006/01/24 07:31:56 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-mixer-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	audio
COMMENT=	Xfce mixer plugin

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
