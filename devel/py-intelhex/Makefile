# $NetBSD: Makefile,v 1.1 2020/12/04 23:30:30 riastradh Exp $

GITHUB_PROJECT=	intelhex
GITHUB_TAG=	2.3.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=python-intelhex/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-intelhex/intelhex
COMMENT=	Python library for Intel HEX files manipulations
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/intelhex-2.3.0
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
