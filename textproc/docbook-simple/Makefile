# $NetBSD: Makefile,v 1.6 2004/04/27 20:53:34 jmmv Exp $
#

DISTNAME=	docbook-simple-1.1b1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://docbook.org/xml/simple/1.1b1/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://docbook.org/xml/simple/
COMMENT=	Simplified DocBook XML DTD

USE_BUILDLINK3=	YES
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

XML_CATALOGS=	${DTDDIR}/catalog

do-install:
	${INSTALL_DATA_DIR} ${DTDDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	(cd ${WRKSRC}; ${INSTALL_DATA} ${MISCFILES} ${DTDDIR})
	${INSTALL_DATA} ${FILESDIR}/catalog ${DTDDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
