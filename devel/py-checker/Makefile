# $NetBSD: Makefile,v 1.29 2020/01/18 23:30:37 rillig Exp $

DISTNAME=	pychecker-0.8.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pychecker.sourceforge.net/
COMMENT=	Python code checker
LICENSE=	modified-bsd

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.8.19

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pychecker ${DESTDIR}${PREFIX}/bin/pychecker${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
