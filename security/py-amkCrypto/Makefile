# $NetBSD: Makefile,v 1.2 2001/05/14 16:22:36 drochner Exp $
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
USE_PYTHON=	yes
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

MAKE_ENV+=	SSLBASE="${SSLBASE}"

do-configure:
	${SED} -e "s|/usr/local/ssl|${SSL_BASE}|g"                  \
		${WRKSRC}/setup.py > ${WRKSRC}/setup.py.tmp
	${MV} -f ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py

.include "../../mk/bsd.pkg.mk"
