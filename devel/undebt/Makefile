# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:09 wiz Exp $

DISTNAME=	undebt-0.2.2
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=u/undebt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Yelp/undebt
COMMENT=	Fast, reliable tool for performing automated code refactoring
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse

PYTHON_VERSIONED_DEPENDENCIES+=	pyparsing

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
