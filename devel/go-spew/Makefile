# $NetBSD: Makefile,v 1.5 2020/03/21 16:57:13 bsiegert Exp $

GITHUB_TAG=		v${PKGVERSION_NOREV}
DISTNAME=		go-spew-1.1.1
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=davecgh/}
GITHUB_PROJECT=		go-spew

MAINTAINER=		ng0@NetBSD.org
HOMEPAGE=		https://github.com/davecgh/go-spew
COMMENT=		Deep pretty printer for Go data structures
LICENSE=		isc

GO_SRCPATH=		github.com/davecgh/go-spew
GO_DIST_BASE=		go-spew-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
