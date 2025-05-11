# $NetBSD: Makefile,v 1.2 2025/05/11 08:25:29 wiz Exp $

DISTNAME=	cpuinfo-0.0.20250219
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=pytorch/}
GITHUB_TAG=	b73ae6ce38d5dd0b7fe46dbe0a4b5f4bab91c7ea

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytorch/cpuinfo/
COMMENT=	CPU information library
LICENSE=	2-clause-bsd

USE_LANGUAGES+=		c

PKGCONFIG_OVERRIDE=	libcpuinfo.pc.in

# not supported by upstream, work started in wip/cpuinfo
BROKEN_ON_PLATFORM+=	NetBSD-*-*

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
