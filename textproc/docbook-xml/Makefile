# $NetBSD: Makefile,v 1.5 2003/01/18 09:39:27 jmmv Exp $
#

DISTNAME=	docbook-xml-4.2
WRKSRC=		${WRKDIR}
PKGREVISION=	3
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

do-install:
	${INSTALL_DATA_DIR} ${DTDDIR}
	${INSTALL_DATA_DIR} ${ENTDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${DTDFILES} ${DTDDIR})
	(cd ${WRKSRC}/ent; ${INSTALL_DATA} *.ent ${ENTDIR})
	(cd ${WRKSRC};     ${INSTALL_DATA} ${MISCFILES} ${DTDDIR})
	${PREFIX}/bin/xmlcatmgr -c ${PREFIX}/share/xml/catalog \
		add "CATALOG" "${PREFIX}/share/xml/docbook/catalog"
	${INSTALL_DATA} ${WRKSRC}/docbook.cat ${DTDDIR}/catalog

.include "../../textproc/xmlcatmgr/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
