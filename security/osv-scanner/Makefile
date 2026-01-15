# $NetBSD: Makefile,v 1.35 2026/01/15 19:54:53 bsiegert Exp $

DISTNAME=	osv-scanner-1.9.1
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/osv-scanner/
COMMENT=	Vulnerability scanner written using the OSV project
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	./cmd/osv-scanner

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
