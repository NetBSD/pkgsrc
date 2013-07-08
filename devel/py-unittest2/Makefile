# $NetBSD: Makefile,v 1.2 2013/07/08 16:17:20 wiz Exp $

DISTNAME=		unittest2-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=	http://pypi.python.org/packages/source/u/unittest2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pypi.python.org/pypi/unittest2
COMMENT=		Unittest features for Python 2.7 backported to Python 2.3+
LICENSE=		original-bsd

PYTHON_VERSIONS_INCLUDE_3X = no

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
PLIST_SUBST+=		DOCDIR=${DOCDIR}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
