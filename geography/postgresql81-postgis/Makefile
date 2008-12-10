# $NetBSD: Makefile,v 1.19 2008/12/10 23:41:20 gdt Exp $

DISTNAME=		postgis-${VERSION}
VERSION=		1.3.4
PKGNAME=		postgresql81-postgis-${VERSION}
MASTER_SITES=		http://postgis.refractions.net/download/
CATEGORIES=		databases geography

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://postgis.refractions.net/
COMMENT=		Spatial database capabilities for PostgreSQL

PKG_DESTDIR_SUPPORT=	user-destdir

# XXX Change to determine postgresql version dynamically.

CONFLICTS=		postgis-[0-9]*

# gmake complains about adding + to parent rule
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake lex pax perl
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

INSTALLATION_DIRS=	${DOCDIR} ${HTMLDIR} ${PKGMANDIR}/man1

# Install is manual because distribution fails if docbook prereqs are not
# satisfied, rather than using the prebuilt versions which are actually
# in the distfile.
do-install:
	cd ${WRKSRC} && ${GMAKE} install DESTDIR=${DESTDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/README.postgis ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/*.xml ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/*.txt ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc/html && pax -rw -pp *.html *.css ${DESTDIR}${HTMLDIR}
	${INSTALL_MAN} ${BUILD_DIRS:Q}/doc/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

TEST_TARGET=		check

DEPENDS+=	postgresql81-server>=8.1:../../databases/postgresql81-server

.include "../../geography/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
# "server" includes are in the client package
.include "../../databases/postgresql81-client/buildlink3.mk"
# needed for docs, also pdfxmltex, db2pdf, jw
#.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
