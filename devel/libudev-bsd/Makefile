# $NetBSD: Makefile,v 1.3 2026/09/22 14:56:01 kikadf Exp $

DISTNAME=	libudev-bsd-0.7.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=kikadf/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://github.com/kikadf/libudev-bsd/
COMMENT=	Libudev compatible interface for BSD systems
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

# Uses NetBSD only ndevd, OpenBSD only KERN_AUTOCONF_SERIAL sysctl
# and devd for Free- and DragonFly BSD
ONLY_FOR_PLATFORM=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-*
ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

.include "../../mk/bsd.prefs.mk"

.include "../../devel/meson/build.mk"
.if ${OPSYS} == "NetBSD"
.include "../../sysutils/ndevd/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
