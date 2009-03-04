# $NetBSD: Makefile,v 1.16 2009/03/04 16:44:28 minskim Exp $
#

DISTNAME=	docbook-simple-1.1
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://docbook.org/xml/simple/1.1/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://docbook.org/xml/simple/
COMMENT=	Simplified DocBook XML DTD

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
NO_CONFIGURE=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}
INSTDIR=	${DESTDIR}${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/docbook/simple/1.1
DTDFILES=	sdbcent.mod sdocbook-custom.dtd sdocbookref-custom.dtd \
		sdbhier.mod sdocbookref.dtd sdbpool.mod sdocbook.dtd \
		sinclist.mod
MISCFILES=	sdocbook.css

XML_CATALOGS=	${DTDDIR}/catalog.xml
XML_ENTRIES=	rewriteSystem http://www.oasis-open.org/docbook/xml/simple/1.1 \
		${DTDDIR}

# share/xml/docbook is shared with docbook-xml.
PRINT_PLIST_AWK+=	/^@dirrm share\/xml\/docbook$$/ \
			{ print "@unexec $${RMDIR} %D/share/xml/docbook" \
			  " >/dev/null 2>&1"; next }

do-install:
	${INSTALL_DATA_DIR} ${DTDDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	(cd ${WRKSRC}; ${INSTALL_DATA} ${MISCFILES} ${DTDDIR})
	${INSTALL_DATA} ${FILESDIR}/catalog.xml.in ${DTDDIR}/catalog.xml

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
