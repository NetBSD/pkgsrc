# $NetBSD: Makefile,v 1.1.1.1 2003/12/13 21:19:18 xtraeme Exp $
#

DISTNAME=	docbook-simple-1.0
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/simple/1.0/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.oasis-open.org/docbook/xml/simple/
COMMENT=	Simplified DocBook XML DTD

NO_BUILD=	YES

INSTDIR=	${DESTDIR}${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/docbook-simple
DTDFILES=	sdbcent.mod sdocbook-custom.dtd sdocbookref-custom.dtd \
		sdbhier.mod sdocbookref.dtd sdbpool.mod sdocbook.dtd \
		sinclist.mod
MISCFILES=	sdocbook.css

XML_CATALOGS=	${DTDDIR}/catalog

do-install:
	${INSTALL_DATA_DIR} ${DTDDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	(cd ${WRKSRC}; ${INSTALL_DATA} ${MISCFILES} ${DTDDIR})
	${INSTALL_DATA} ${FILESDIR}/catalog ${DTDDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
