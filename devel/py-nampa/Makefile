# $NetBSD: Makefile,v 1.1 2023/05/11 05:23:30 adam Exp $

DISTNAME=	nampa-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nampa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kenoph/nampa
COMMENT=	FLIRT signatures for Python
LICENSE=	gnu-lgpl-v3



PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} dumpsig.py dumpsig-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
