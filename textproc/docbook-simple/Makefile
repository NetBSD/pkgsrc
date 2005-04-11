# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:33 tv Exp $
#

DISTNAME=	docbook-simple-1.1CR2
PKGNAME=	${DISTNAME:C/CR/rc/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://docbook.org/xml/simple/1.1CR2/
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

XML_ENTRIES=	public "-//OASIS//DTD Simplified DocBook XML V1.1CR2//EN" \
		${PREFIX}/share/xml/docbook-simple/sdocbook.dtd
XML_ENTRIES+=	public "-//OASIS//DTD Simplified DocBook RefEntry XML V1.1CR2//EN" \
		${PREFIX}/share/xml/docbook-simple/sdocbookref.dtd

do-install:
	${INSTALL_DATA_DIR} ${DTDDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	(cd ${WRKSRC}; ${INSTALL_DATA} ${MISCFILES} ${DTDDIR})

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
