# $NetBSD: Makefile,v 1.11 2005/05/05 19:20:45 hrs Exp $
#

DISTNAME=	docbook-simple-1.1
PKGREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	http://docbook.org/xml/simple/1.1/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://docbook.org/xml/simple/
COMMENT=	Simplified DocBook XML DTD

USE_LANGUAGES=	# empty
NO_CONFIGURE=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}
INSTDIR=	${DESTDIR}${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/docbook-simple
DTDFILES=	sdbcent.mod sdocbook-custom.dtd sdocbookref-custom.dtd \
		sdbhier.mod sdocbookref.dtd sdbpool.mod sdocbook.dtd \
		sinclist.mod
MISCFILES=	sdocbook.css

XML_CATALOGS=	${PREFIX}/share/xml/docbook-simple/catalog.xml

do-install:
	${INSTALL_DATA_DIR} ${DTDDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	(cd ${WRKSRC}; ${INSTALL_DATA} ${MISCFILES} ${DTDDIR})
	${INSTALL_DATA} ${FILESDIR}/catalog.xml.in ${DTDDIR}/catalog.xml

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
