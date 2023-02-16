# $NetBSD: Makefile,v 1.4 2023/02/16 15:02:00 bsiegert Exp $

DISTNAME=	osv-scanner-1.0.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/osv-scanner/
COMMENT=	Vulnerability scanner written using the OSV project
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
