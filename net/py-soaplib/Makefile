# $NetBSD: Makefile,v 1.1.1.1 2001/05/19 12:52:18 drochner Exp $
#

DISTNAME=	soaplib-0.8-20000621
PKGNAME=	py-soaplib-0.8
CATEGORIES=	net
MASTER_SITES=	http://www.pythonware.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/soap/index.htm
COMMENT=	implementation of the SOAP 1.1 protocol

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PYTHON=	yes
PY_PATCHPLIST=	yes

do-install:
	for i in soaplib.py soapserver.py; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/${PYSITELIB}; \
	done

.include "../../mk/bsd.pkg.mk"
