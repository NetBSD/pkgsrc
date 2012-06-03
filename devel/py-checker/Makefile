# $NetBSD: Makefile,v 1.16 2012/06/03 22:32:59 wiz Exp $

DISTNAME=	pychecker-0.8.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	Python code checker
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pychecker ${DESTDIR}${PREFIX}/bin/pychecker${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
