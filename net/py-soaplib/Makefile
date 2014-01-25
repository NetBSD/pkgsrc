# $NetBSD: Makefile,v 1.16 2014/01/25 10:30:17 wiz Exp $

DISTNAME=	soaplib-0.8-20000621
PKGNAME=	${PYPKGPREFIX}-soaplib-0.8
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://www.pythonware.com/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.pythonware.com/products/soap/index.htm
COMMENT=	Implementation of the SOAP 1.1 protocol

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

PY_PATCHPLIST=	yes

INSTALLATION_DIRS=	${PYSITELIB}

do-install:
	for i in soaplib.py soapserver.py; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/${PYSITELIB}; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
