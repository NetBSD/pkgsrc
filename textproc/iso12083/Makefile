# $NetBSD: Makefile,v 1.15 2005/12/05 20:51:03 rillig Exp $

DISTNAME=	iso12083-1993
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	ftp://info.ex.ac.uk/pub/SGML/ISO-12083/ \
		ftp://ftp.ifi.uio.no/pub/SGML/ISO12083/ \
		ftp://ftp.oit.unc.edu/pub/packages/SGML/oslo-mirror/ISO12083/
DISTFILES=	article.dtd book.dtd maths.dtd serial.dtd

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.oasis-open.org/cover/sgml-xml.html
COMMENT=	SGML DTDs from the The Electronic Publishing Special Interest Group

DIST_SUBDIR=	iso12083

WRKSRC=		${WRKDIR}
NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

INSTDIR=	${PREFIX}/share/sgml/iso12083

SGML_CATALOGS=	${INSTDIR}/catalog

pre-install:
	${INSTALL_DATA_DIR} ${INSTDIR}

do-install:
	@for i in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$i ${INSTDIR}/$$i; \
	done
	@${INSTALL_DATA} ${FILESDIR}/catalog ${INSTDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
