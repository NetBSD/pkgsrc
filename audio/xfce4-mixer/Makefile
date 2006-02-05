# $NetBSD: Makefile,v 1.15 2006/02/05 23:08:16 joerg Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-mixer-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	audio
COMMENT=	Xfce mixer plugin

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
