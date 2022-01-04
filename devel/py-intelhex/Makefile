# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:11 wiz Exp $

GITHUB_PROJECT=	intelhex
GITHUB_TAG=	2.3.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	1
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
