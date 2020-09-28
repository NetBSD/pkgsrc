# $NetBSD: vex.mk,v 1.3 2020/09/28 22:56:38 khorben Exp $

DISTNAME=	vex-0.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_TAG=	4648030b364608388b33e1cfd90409e981406982

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/vex/
COMMENT=	Patched version of VEX to work with PyVEX
LICENSE=	2-clause-bsd

.include "../../mk/bsd.pkg.mk"
