# $NetBSD: Makefile,v 1.86 2025/10/23 20:38:19 wiz Exp $
#

DISTNAME=		gkrellmoon-0.6
PKGNAME=		gkrellm-moon-0.6
PKGREVISION=		67
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gkrellmoon/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gkrellmoon.sourceforge.net/
COMMENT=		GKrellM2 moonclock plugin
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		pkg-config
BUILD_TARGET=		gkrellmoon.so

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
