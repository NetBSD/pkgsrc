# $NetBSD: Makefile,v 1.10 2004/01/23 17:18:31 jmmv Exp $
#

DISTNAME=	docbook-xml-4.2
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/4.2/
EXTRACT_SUFX=	.zip

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.oasis-open.org/docbook
COMMENT=	XML DTD designed for computer documentation

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	YES
NO_BUILD=	YES

INSTDIR=	${DESTDIR}${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/docbook
ENTDIR=		${INSTDIR}/docbook/ent
DTDFILES=	calstblx.dtd dbcentx.mod dbgenent.mod dbhierx.mod \
		dbnotnx.mod dbpoolx.mod docbookx.dtd soextblx.dtd
MISCFILES=	README

XML_CATALOGS=	${DTDDIR}/catalog

do-install:
	${INSTALL_DATA_DIR} ${DTDDIR}
	${INSTALL_DATA_DIR} ${ENTDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	(cd ${WRKSRC}/ent; ${INSTALL_DATA} *.ent ${ENTDIR})
	(cd ${WRKSRC};     ${INSTALL_DATA} ${MISCFILES} ${DTDDIR})
	${INSTALL_DATA} ${WRKSRC}/catalog.xml ${DTDDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
