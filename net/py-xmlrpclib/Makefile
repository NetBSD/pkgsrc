# $NetBSD: Makefile,v 1.1.1.1 2001/05/19 12:50:56 drochner Exp $
#

DISTNAME=	xmlrpc-0.9.8-990621
PKGNAME=	py-xmlrpc-0.9.8
CATEGORIES=	net
MASTER_SITES=	http://www.pythonware.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/xmlrpc/
COMMENT=	implementation of the XML-RPC protocol for Python

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PYTHON=	yes
PY_PATCHPLIST=	yes

do-install:
	for f in ${WRKSRC}/*.py; do \
		${INSTALL_DATA} $$f ${PREFIX}/${PYSITELIB}; \
	done

.include "../../mk/bsd.pkg.mk"
