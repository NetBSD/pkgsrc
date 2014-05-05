# $NetBSD: Makefile,v 1.28 2014/05/05 00:48:13 ryoon Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.2

DISTNAME=	xfce4-mpc-plugin-${XFCE4_VERSION}
EXTRACT_SUFX=		.tar.gz
PKGREVISION=	21
CATEGORIES=	multimedia
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-mpc-plugin/
COMMENT=	Xfce Music Player Client plugin

LIBS.SunOS+=	-lsocket -lnsl

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
