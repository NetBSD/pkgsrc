# $NetBSD: Makefile,v 1.2 2003/12/23 22:25:29 wiz Exp $
#

DISTNAME=	docbook-simple-1.1b1
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	http://docbook.org/xml/simple/1.1b1/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://docbook.org/xml/simple/
COMMENT=	Simplified DocBook XML DTD

NO_CONFIGURE=	YES
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
