# $NetBSD: Makefile,v 1.6 2017/01/03 13:23:02 jperkin Exp $

DISTNAME=		unittest2py3k-0.5.1
# to match python-2.x name
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py3k//}
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_PYPI:=u/unittest2py3k/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pypi.python.org/pypi/unittest2py3k
COMMENT=		Unittest features for Python 2.7 (Python 3.x version)
LICENSE=		original-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
PLIST_SUBST+=		DOCDIR=${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${RM} -f ${DESTDIR}${PREFIX}/bin/unit2
	${MV} ${DESTDIR}${PREFIX}/bin/unit2.py \
		${DESTDIR}${PREFIX}/bin/unit2-${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
