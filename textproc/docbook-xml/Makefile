# $NetBSD: Makefile,v 1.33 2009/06/14 22:58:09 joerg Exp $
#

DISTNAME=	docbook-xml-4.4
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/xml/4.4/
SITES.docbook-xml-4.3.zip=	http://www.oasis-open.org/docbook/xml/4.3/
SITES.docbook-xml-4.2.zip=	http://www.oasis-open.org/docbook/xml/4.2/
DISTFILES=	docbook-xml-4.2.zip docbook-xml-4.3.zip docbook-xml-4.4.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oasis-open.org/docbook/
COMMENT=	XML DTD designed for computer documentation

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# empty
USE_TOOLS+=	unzip
NO_BUILD=	YES
EXTRACT_ONLY=	# empty

INSTDIR=	${PREFIX}/share/xml
DTDDIR=		${INSTDIR}/docbook

VER=		4.2 4.3 4.4

XML_CATALOGS=
XML_ENTRIES=
.for ver in ${VER}
XML_CATALOGS+= ${DTDDIR}/${ver}/catalog
XML_ENTRIES+=	rewriteSystem http://www.oasis-open.org/docbook/xml/${ver} \
		${DTDDIR}/${ver}
.endfor

# 4.2 is backwards-compatible with 4.1.2, so we just make 4.1.2 be an alias
# for 4.2.
XML_CATALOGS+= ${DTDDIR}/4.2/catalog-4.1.2
XML_ENTRIES+=	rewriteSystem http://www.oasis-open.org/docbook/xml/4.1.2 \
		${DTDDIR}/4.2

pre-install:
.for ver in ${VER}
	${INSTALL_DATA_DIR} ${DESTDIR}${DTDDIR}/${ver}
.endfor

do-install:
.for ver in ${VER}
	cd ${DESTDIR}${DTDDIR}/${ver} && ${UNZIP_CMD} ${DISTDIR}/docbook-xml-${ver}.zip
	cd ${DESTDIR}${DTDDIR}/${ver} && ${MV} catalog.xml catalog
.endfor
	${SED} -e 's|V4.2|V4.1.2|g' <${DESTDIR}${DTDDIR}/4.2/catalog \
	    >${DESTDIR}${DTDDIR}/4.2/catalog-4.1.2

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
