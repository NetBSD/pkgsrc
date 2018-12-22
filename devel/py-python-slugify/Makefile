# $NetBSD: Makefile,v 1.3 2018/12/22 17:14:35 taca Exp $

DISTNAME=	python-slugify-1.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-slugify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/un33k/python-slugify
COMMENT=	Slugify application that handles Unicode
LICENSE=	mit

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04.16:../../textproc/py-Unidecode

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/slugify \
		${DESTDIR}${PREFIX}/bin/slugify${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
