# $NetBSD: Makefile,v 1.1 2026/04/13 15:43:44 kikadf Exp $

DISTNAME=		libliftoff-0.5.0
CATEGORIES=		graphics
MASTER_SITE_GITLAB=	https://gitlab.freedesktop.org/
MASTER_SITES=		${MASTER_SITE_GITLAB:=emersion/}
GITLAB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://gitlab.freedesktop.org/emersion/libliftoff
COMMENT=	Lightweight KMS plane library
LICENSE=	mit

USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/libliftoff-${GITLAB_TAG}

.include "../../devel/meson/build.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
