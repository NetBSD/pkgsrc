# $NetBSD: Makefile,v 1.8 2003/07/21 17:11:12 martti Exp $
#

DISTNAME=	xmlrpc-0.9.8-990621
PKGNAME=	${PYPKGPREFIX}-xmlrpc-0.9.8
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://www.pythonware.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/xmlrpc/
COMMENT=	Implementation of the XML-RPC protocol for Python

NO_BUILD=	yes

PY_PATCHPLIST=	yes

do-install:
	for f in ${WRKSRC}/*.py; do \
		${INSTALL_DATA} $$f ${PREFIX}/${PYSITELIB}; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
