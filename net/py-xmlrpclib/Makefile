# $NetBSD: Makefile,v 1.6 2003/03/29 12:42:02 jmmv Exp $
#

DISTNAME=	xmlrpc-0.9.8-990621
PKGNAME=	${PYPKGPREFIX}-xmlrpc-0.9.8
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://www.pythonware.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@netbsd.org
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
