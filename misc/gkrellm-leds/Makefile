# $NetBSD: Makefile,v 1.82 2026/01/27 08:40:08 wiz Exp $
#

DISTNAME=	gkleds-0.8.2
PKGNAME=	${DISTNAME:S/^gk/gkrellm-/}
PKGREVISION=	65
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/96/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GKrellM plugin that monitors CapsLock, NumLock and ScrollLock keys

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

GNU_CONFIGURE_LIBSUBDIR=	gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
