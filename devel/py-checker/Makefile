# $NetBSD: Makefile,v 1.21 2016/07/09 13:03:40 wiz Exp $

DISTNAME=	pychecker-0.8.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	Python code checker
LICENSE=	modified-bsd

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.8.19

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pychecker ${DESTDIR}${PREFIX}/bin/pychecker${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
