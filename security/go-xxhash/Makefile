# $NetBSD: Makefile,v 1.8 2020/06/17 09:54:15 bsiegert Exp $

GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		go-xxhash-2.1.0
PKGREVISION=		6
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=cespare/}
GITHUB_PROJECT=		xxhash

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://github.com/cespare/xxhash/
COMMENT=		Go implementation of the 64bit xxhash algorithm XXh64
LICENSE=		mit

GO_SRCPATH=		github.com/cespare/xxhash
GO_DIST_BASE=		xxhash-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
