# $NetBSD: Makefile,v 1.9 2004/01/20 12:22:20 agc Exp $
#

DISTNAME=	xmlrpc-0.9.8-990621
PKGNAME=	${PYPKGPREFIX}-xmlrpc-0.9.8
CATEGORIES=	net
MASTER_SITES=	http://www.pythonware.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/xmlrpc/
COMMENT=	Implementation of the XML-RPC protocol for Python

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

PY_PATCHPLIST=	yes

do-install:
	for f in ${WRKSRC}/*.py; do \
		${INSTALL_DATA} $$f ${PREFIX}/${PYSITELIB}; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
