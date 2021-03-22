# $NetBSD: Makefile,v 1.3 2021/03/22 11:03:27 markd Exp $

DISTNAME=	gitdb-4.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gitdb/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/gitpython-developers/gitdb
COMMENT=	Git Object Database
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-smmap-[0-9]*:../../devel/py-smmap

# No reason to restrict this to smmap<4 (no significant changes in API).
SUBST_CLASSES+=		deps
SUBST_FILES.deps=	${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/requires.txt
SUBST_SED.deps=		-e 's:smmap<4,:smmap:'
SUBST_STAGE.deps=	post-install

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
