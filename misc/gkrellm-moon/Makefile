# $NetBSD: Makefile,v 1.34 2012/09/15 10:05:35 obache Exp $
#

DISTNAME=		gkrellmoon-0.6
PKGNAME=		gkrellm-moon-0.6
PKGREVISION=		18
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gkrellmoon/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gkrellmoon.sourceforge.net/
COMMENT=		GKrellM2 moonclock plugin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
BUILD_TARGET=		gkrellmoon.so

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
