# $NetBSD: Makefile,v 1.1.1.1 2001/05/07 00:56:48 wiz Exp $
#

DISTNAME=	amkCrypto-0.1.3
PKGNAME=	py-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.amk.ca/files/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	cryptographic and hash functions for Python

DEPENDS+= 	python-2.*:../../lang/python

USE_SSL=	YES
PLIST_SRC=	${WRKDIR}/PLIST
# we borrow py-Scientific's printpypath
FILESDIR=	${.CURDIR}/../../math/py-Scientific/files
MAKE_ENV+=	SSLBASE="${SSLBASE}"

do-configure:
	${SED} -e "s|/usr/local/ssl|${SSL_BASE}|g"                  \
		${WRKSRC}/setup.py > ${WRKSRC}/setup.py.tmp
	${MV} -f ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/python setup.py build

post-build:
	eval `${LOCALBASE}/bin/python ${FILESDIR}/printpypath.py` && \
	${SED} "s|PYINC|$${PYINC}|g;s|PYSITELIB|$${PYSITELIB}|g" \
	${PKGDIR}/PLIST >${PLIST_SRC}

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/bin/python setup.py install

.include "../../mk/bsd.pkg.mk"
