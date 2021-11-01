# $NetBSD: Makefile,v 1.4 2021/11/01 18:58:33 wiz Exp $

DISTNAME=	undebt-0.2.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=u/undebt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Yelp/undebt
COMMENT=	Fast, reliable tool for performing automated code refactoring
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse

PYTHON_VERSIONED_DEPENDENCIES+=	pyparsing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
