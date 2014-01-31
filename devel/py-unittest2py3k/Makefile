# $NetBSD: Makefile,v 1.1 2014/01/31 11:23:13 wiz Exp $

DISTNAME=		unittest2py3k-0.5.1
# to match python-2.x name
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py3k//}
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/u/unittest2py3k/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pypi.python.org/pypi/unittest2py3k
COMMENT=		Unittest features for Python 2.7 (Python 3.x version)
LICENSE=		original-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	26 27

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
PLIST_SUBST+=		DOCDIR=${DOCDIR}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
