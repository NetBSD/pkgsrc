# $NetBSD: Makefile,v 1.6 2003/01/29 21:17:26 jmmv Exp $
#

DISTNAME=	docbook-xml-4.2
WRKSRC=		${WRKDIR}
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/4.2/
EXTRACT_SUFX=	.zip

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://www.oasis-open.org/docbook
COMMENT=	XML DTD designed for computer documentation

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
