# $NetBSD: Makefile,v 1.10 2021/02/01 17:13:39 schmonz Exp $

DISTNAME=	${GITHUB_PROJECT}-1.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=remotemobprogramming/}
GITHUB_PROJECT=	mob
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://mob.sh/
COMMENT=	Swift git handover during remote mob programming
LICENSE=	mit

GO_DIST_BASE=	${PKGNAME_NOREV}
GO_SRCPATH=	github.com/remotemobprogramming/mob

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
