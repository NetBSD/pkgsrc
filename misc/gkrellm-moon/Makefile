# $NetBSD: Makefile,v 1.13 2004/12/03 15:15:04 wiz Exp $
#

DISTNAME=		gkrellmoon-0.6
PKGNAME=		gkrellm-moon-0.6
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gkrellmoon/}

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://gkrellmoon.sourceforge.net/
COMMENT=		GKrellM2 moonclock plugin

USE_BUILDLINK3=		yes
BUILD_TARGET=		gkrellmoon.so

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
