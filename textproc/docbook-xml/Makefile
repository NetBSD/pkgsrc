# $NetBSD: Makefile,v 1.1.1.1 2001/11/04 22:46:58 seb Exp $
#

DISTNAME=	docbkx412
PKGNAME=	docbook-xml-4.1.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/4.1.2/
EXTRACT_SUFX=	.zip

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://www.oasis-open.org/docbook
COMMENT=	XML DTD designed for computer documentation

WRKSRC=		${WRKDIR}

INSTDIR=	${DESTDIR}${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/docbook
ENTDIR=		${INSTDIR}/docbook/ent
DTDFILES=	calstblx.dtd dbcentx.mod dbgenent.mod dbhierx.mod \
		dbnotnx.mod dbpoolx.mod docbookx.dtd soextblx.dtd
MISCFILES=	40chg.txt 41chg.txt readme.txt

do-build:
	${ECHO} 'CATALOG "${PREFIX}/share/xml/docbook/catalog"' \
		> ${WRKSRC}/catalog
	${GREP} '^PUBLIC' ${WRKSRC}/docbook.cat > ${WRKSRC}/catalog.docbook

do-install:
	${INSTALL_DATA_DIR} ${DTDDIR}
	${INSTALL_DATA_DIR} ${ENTDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	(cd ${WRKSRC}/ent; ${INSTALL_DATA} *.ent ${ENTDIR})
	(cd ${WRKSRC};     ${INSTALL_DATA} ${MISCFILES} ${DTDDIR})
	${INSTALL_DATA} ${WRKSRC}/catalog ${INSTDIR}/catalog
	${INSTALL_DATA} ${WRKSRC}/catalog.docbook ${DTDDIR}/catalog

.include "../../mk/bsd.pkg.mk"
