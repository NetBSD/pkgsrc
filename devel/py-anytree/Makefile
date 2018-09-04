# $NetBSD: Makefile,v 1.1 2018/09/04 12:44:41 wiz Exp $

DISTNAME=	anytree-2.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anytree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://anytree.readthedocs.io/
COMMENT=	Powerful and Lightweight Python Tree Data Structure
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
