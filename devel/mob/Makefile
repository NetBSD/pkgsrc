# $NetBSD: Makefile,v 1.20 2021/07/13 11:36:43 bsiegert Exp $

DISTNAME=	${GITHUB_PROJECT}-1.7.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=remotemobprogramming/}
GITHUB_PROJECT=	mob
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://mob.sh/
COMMENT=	Swift git handover during remote mob programming
LICENSE=	mit

GO_BUILD_PATTERN=	.

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
