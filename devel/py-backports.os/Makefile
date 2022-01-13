# $NetBSD: Makefile,v 1.3 2022/01/13 19:31:23 wiz Exp $

DISTNAME=	backports.os-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.os/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pjdelport/backports.os
COMMENT=	Backport of new features in Python's os module
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-backports-[0-9]*:../../devel/py-backports
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm5

PYTHON_VERSIONS_ACCEPTED=	27 # py-backports

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
