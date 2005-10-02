# $NetBSD: Makefile,v 1.20 2005/10/02 15:04:41 jmmv Exp $
#

DISTNAME=	docbook-xml-4.4
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/4.4/
SITES_docbook-xml-4.3.zip=	http://www.oasis-open.org/docbook/xml/4.3/
SITES_docbook-xml-4.2.zip=	http://www.oasis-open.org/docbook/xml/4.2/
DISTFILES=	docbook-xml-4.2.zip docbook-xml-4.3.zip docbook-xml-4.4.zip

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.oasis-open.org/docbook/
COMMENT=	XML DTD designed for computer documentation

BUILD_DEPENDS=	unzip-[0-9]*:../../archivers/unzip

PKG_INSTALLATION_TYPES= overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
NO_BUILD=	YES
EXTRACT_ONLY=	# empty

INSTDIR=	${DESTDIR}${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/docbook

VER=		4.2 4.3 4.4

XML_CATALOGS=
.for ver in ${VER}
XML_CATALOGS+= ${DTDDIR}/${ver}/catalog
.endfor
XML_CATALOGS+= ${DTDDIR}/4.2/catalog-4.1.2

pre-install:
.for ver in ${VER}
	@[ -d ${DTDDIR}/${ver} ] || ${INSTALL_DATA_DIR} ${DTDDIR}/${ver}
.endfor

do-install:
.for ver in ${VER}
	@(cd ${DTDDIR}/${ver}; unzip ${DISTDIR}/docbook-xml-${ver}.zip)
	@(cd ${DTDDIR}/${ver}; ${MV} catalog.xml catalog)
.endfor
	@${SED} -e 's|V4.2|V4.1.2|g' <${DTDDIR}/4.2/catalog \
	    >${DTDDIR}/4.2/catalog-4.1.2

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
