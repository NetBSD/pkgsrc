# $NetBSD: Makefile,v 1.3.2.1 2002/06/23 18:59:21 jlam Exp $
#

DISTNAME=	amkCrypto-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.amk.ca/files/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	cryptographic and hash functions for Python

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

CONFIGURE_ENV+=	SSLBASE=${SSLBASE}

do-configure:
	${SED} -e "s|/usr/local/ssl|${SSLBASE}|g"                  \
		${WRKSRC}/setup.py > ${WRKSRC}/setup.py.tmp
	${MV} -f ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py

.include "../../security/openssl/buildlink.mk"
.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
