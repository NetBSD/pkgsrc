# $NetBSD: vex.mk,v 1.5 2023/05/11 07:16:04 adam Exp $

.include "../../devel/py-angr/version.mk"

DISTNAME=	vex-0.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_TAG=	v${ANGR_VERSION}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/vex
COMMENT=	Patched version of VEX to work with PyVEX
LICENSE=	2-clause-bsd

.include "../../mk/bsd.pkg.mk"
