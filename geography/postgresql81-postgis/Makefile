# $NetBSD: Makefile,v 1.14 2008/02/04 20:10:35 tnn Exp $

DISTNAME=		postgis-${VERSION}
VERSION=		1.3.2
PKGNAME=		postgresql81-postgis-${VERSION}
MASTER_SITES=		http://postgis.refractions.net/download/
PKGREVISION=		1
CATEGORIES=		databases geography

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://postgis.refractions.net/
COMMENT=		Spatial database capabilities for PostgreSQL

# XXX Change to determine postgresql version dynamically.

CONFLICTS=		postgis-[0-9]*

# gmake complains about adding + to parent rule
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake lex perl
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/postgresql/contrib
#CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/postgresql

DOCDIR=		${PREFIX}/share/doc/postgis
HTMLDIR=	${PREFIX}/share/doc/html/postgis

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	extras/template_gis/profile \
			extras/template_gis/createdb.postgis.1 \
			extras/template_gis/mktemplate_gis.1 \
			extras/template_gis/postgis_env.sh.in
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_STAGE.paths=	pre-configure

# Install is manual because distribution fails if docbook prereqs are not
# satisfied, rather than using the prebuilt versions which are actually
# in the distfile.
do-install:
	cd ${WRKSRC} && ${GMAKE} install
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/README.postgis ${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/*.xml ${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/*.txt ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc/html && ${PAX} -rw -pp *.html *.css ${HTMLDIR}
	${INSTALL_MAN} ${BUILD_DIRS:Q}/doc/man/*.1 ${PREFIX}/${PKGMANDIR}/man1

DEPENDS+=	postgresql81-server>=8.1:../../databases/postgresql81-server

.include "../../geography/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
# "server" includes are in the client package
.include "../../databases/postgresql81-client/buildlink3.mk"
# needed for docs, also pdfxmltex, db2pdf, jw
#.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
