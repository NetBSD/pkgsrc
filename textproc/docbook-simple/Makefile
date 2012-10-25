# $NetBSD: Makefile,v 1.19 2012/10/25 06:55:47 asau Exp $
#

DISTNAME=	docbook-simple-1.1
PKGREVISION=	4
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
DTDDIR=		${PREFIX}/share/xml/docbook/simple/1.1
DTDFILES=	sdbcent.mod sdocbook-custom.dtd sdocbookref-custom.dtd \
		sdbhier.mod sdocbookref.dtd sdbpool.mod sdocbook.dtd \
		sinclist.mod
MISCFILES=	sdocbook.css

XML_CATALOGS=	${DTDDIR}/catalog.xml
XML_ENTRIES=	rewriteSystem http://www.oasis-open.org/docbook/xml/simple/1.1 \
		${DTDDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DTDDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${DTDFILES} ${DESTDIR}${DTDDIR})
	(cd ${WRKSRC}; ${INSTALL_DATA} ${MISCFILES} ${DESTDIR}${DTDDIR})
	${INSTALL_DATA} ${FILESDIR}/catalog.xml.in \
	    ${DESTDIR}${DTDDIR}/catalog.xml

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
