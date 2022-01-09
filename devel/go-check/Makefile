# $NetBSD: Makefile,v 1.44 2022/01/09 20:10:31 bsiegert Exp $
#

DISTNAME=		go-check-1
PKGREVISION=		42
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=go-check/}
GITHUB_PROJECT=		check
GITHUB_TAG=		4f90aea

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		https://labix.org/gocheck
COMMENT=		Rich testing for the Go language
LICENSE=		2-clause-bsd

GO_SRCPATH=		gopkg.in/check.v1
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
