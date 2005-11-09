# $NetBSD: Makefile,v 1.13 2005/11/09 07:09:04 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-mixer-${XFCE4_VERSION}
CATEGORIES=	audio
COMMENT=	Xfce mixer plugin

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
