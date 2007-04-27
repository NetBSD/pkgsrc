# $NetBSD: Makefile,v 1.1.1.1 2007/04/27 10:48:06 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.0

DISTNAME=	xfce4-radio-plugin-${XFCE4_VERSION}
CATEGORIES=	multimedia
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-radio-plugin/
EXTRACT_SUFX=	.tar.gz
COMMENT=	Xfce V4L radio plugin

ONLY_FOR_PLATFORM=	Linux-*-*	# V4L

BROKEN=		Must fix the PLIST first

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
