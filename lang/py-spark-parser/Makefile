# $NetBSD: Makefile,v 1.4 2022/01/31 09:48:35 wiz Exp $

DISTNAME=	spark_parser-1.8.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spark_parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-spark
COMMENT=	Earley-Algorithm Context-free grammar Parser Toolkit
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.0:../../devel/py-nose

PYTHON_VERSIONED_DEPENDENCIES+=	click

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} spark-parser-coverage spark-parser-coverage-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
