# $NetBSD: Makefile,v 1.4 2002/01/17 11:31:57 drochner Exp $
#

DISTNAME=	xmlrpc-0.9.8-990621
PKGNAME=	${PYPKGPREFIX}-xmlrpc-0.9.8
CATEGORIES=	net
MASTER_SITES=	http://www.pythonware.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/xmlrpc/
COMMENT=	implementation of the XML-RPC protocol for Python

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

PY_PATCHPLIST=	yes

do-install:
	for f in ${WRKSRC}/*.py; do \
		${INSTALL_DATA} $$f ${PREFIX}/${PYSITELIB}; \
	done

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
