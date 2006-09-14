# $NetBSD: Makefile,v 1.2 2006/09/14 19:16:43 gdt Exp $

DISTNAME=		postgis-${VERSION}
VERSION=		1.1.3
PKGNAME=		postgresql81-postgis-${VERSION}
MASTER_SITES=	  	http://postgis.refractions.net/download/
CATEGORIES=		databases geography

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://postgis.refractions.net/
COMMENT=		Spatial database capabilities for PostgreSQL

# XXX Change to determine postgresql version dynamically.

CONFLICTS=		postgis-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl
USE_LANGUAGES+=		c c++

CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/postgresql/contrib
#CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/postgresql

# Work around geos and proj not providing -R via foo-config/pkg-config.
# XXX Deal with this correctly.
LDFLAGS+=	-L${PREFIX}/lib -R${PREFIX}/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

DOCDIR=		${PREFIX}/share/doc/postgis
HTMLDIR=	${PREFIX}/share/doc/html/postgis

# Install is manual because distribution fails if docbook prereqs are not
# satisfied, rather than using the prebuilt versions which are actually
# in the distfile.
do-install:
	cd ${WRKSRC} && ${GMAKE} install
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/README.postgis ${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/postgis.xml ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc/html && ${PAX} -rw -pp *.html *.css ${HTMLDIR}

# XXX Perhaps this should be run-depends only.
DEPENDS+=	postgresql81-server>=8.1:../../databases/postgresql81-server

.include "../../geography/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
# "server" includes are in the client package
.include "../../databases/postgresql81-client/buildlink3.mk"
# needed for docs, also pdfxmltex, db2pdf, jw
#.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
