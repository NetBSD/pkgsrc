# $NetBSD: vex.mk,v 1.1 2018/03/15 02:49:25 khorben Exp $

DISTNAME=	vex-0.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=angr/}
GITHUB_TAG=	7394e917fc86c8f042d8ce51a609810a97c20fd7

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/angr/vex/
COMMENT=	Patched version of VEX to work with PyVEX
LICENSE=	2-clause-bsd

.include "../../mk/bsd.pkg.mk"
