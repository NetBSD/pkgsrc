# $NetBSD: Makefile,v 1.7 2003/07/17 22:51:44 grant Exp $
#

DISTNAME=	xmlrpc-0.9.8-990621
PKGNAME=	${PYPKGPREFIX}-xmlrpc-0.9.8
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://www.pythonware.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/xmlrpc/
COMMENT=	implementation of the XML-RPC protocol for Python

NO_BUILD=	yes

PY_PATCHPLIST=	yes

do-install:
	for f in ${WRKSRC}/*.py; do \
		${INSTALL_DATA} $$f ${PREFIX}/${PYSITELIB}; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
