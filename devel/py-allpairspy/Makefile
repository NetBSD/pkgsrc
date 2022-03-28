# $NetBSD: Makefile,v 1.1 2022/03/28 15:58:29 schmonz Exp $

DISTNAME=		allpairspy-2.5.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_PYPI:=a/allpairspy/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/thombashi/allpairspy
COMMENT=		Pairwise test combinations generator
LICENSE=		mit

DEPENDS+=		${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
#TEST_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
