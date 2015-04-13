# $NetBSD: Makefile,v 1.3 2015/04/13 23:12:41 rodent Exp $

DISTNAME=		unittest2py3k-0.5.1
# to match python-2.x name
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py3k//}
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/u/unittest2py3k/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pypi.python.org/pypi/unittest2py3k
COMMENT=		Unittest features for Python 2.7 (Python 3.x version)
LICENSE=		original-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
PLIST_SUBST+=		DOCDIR=${DOCDIR}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${RM} ${DESTDIR}${PREFIX}/bin/unit2
	${MV} ${DESTDIR}${PREFIX}/bin/unit2.py \
		${DESTDIR}${PREFIX}/bin/unit2-${PYVERSSUFFIX}.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
