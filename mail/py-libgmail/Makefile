# $NetBSD: Makefile,v 1.2 2008/04/25 20:39:10 joerg Exp $
#

DISTNAME=	libgmail-0.1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libgmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/libgmail/
COMMENT=	Python bindings to access Google mail

PYTHON_VERSIONS_ACCEPTED=	25 24
PYSETUP=		setup.py
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} install

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
