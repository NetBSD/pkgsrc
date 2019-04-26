# $NetBSD: Makefile,v 1.26 2019/04/26 13:13:51 maya Exp $

DISTNAME=	pychecker-0.8.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	Python code checker
LICENSE=	modified-bsd

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 0.8.19

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pychecker ${DESTDIR}${PREFIX}/bin/pychecker${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
