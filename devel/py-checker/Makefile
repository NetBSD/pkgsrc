# $NetBSD: Makefile,v 1.30 2020/03/20 11:57:30 nia Exp $

DISTNAME=	pychecker-0.8.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	Python code checker
LICENSE=	modified-bsd

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.8.19

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pychecker ${DESTDIR}${PREFIX}/bin/pychecker${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
