# $NetBSD: Makefile,v 1.7 2014/06/23 10:43:45 rodent Exp $

DISTNAME=		unittest2-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=	http://pypi.python.org/packages/source/u/unittest2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pypi.python.org/pypi/unittest2
COMMENT=		Unittest features for Python 2.7 (Python 2.x version)
LICENSE=		original-bsd

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
PLIST_SUBST+=		DOCDIR=${DOCDIR}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # see versioned_dependencies.mk

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${RM} ${DESTDIR}${PREFIX}/bin/unit2
	${MV} ${DESTDIR}${PREFIX}/bin/unit2.py \
		${DESTDIR}${PREFIX}/bin/unit2-${PYVERSSUFFIX}.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
