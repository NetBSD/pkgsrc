# $NetBSD: Makefile,v 1.16 2014/01/02 15:41:03 jperkin Exp $

DISTNAME=	postgis-1.5.3
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	databases geography
MASTER_SITES=	http://postgis.refractions.net/download/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://postgis.refractions.net/
COMMENT=	Spatial database capabilities for PostgreSQL

LICENSE=	gnu-gpl-v2

DEPENDS+=		postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

CONFLICTS=		postgis-[0-9]*

# gmake complains about adding + to parent rule
MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake lex pax perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/postgresql/contrib

TEST_TARGET=		check

DOCDIR=			${PREFIX}/share/doc/postgis

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	extras/template_gis/profile \
			extras/template_gis/createdb.postgis.1 \
			extras/template_gis/mktemplate_gis.1 \
			extras/template_gis/postgis_env.sh.in
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	${DOCDIR} ${DOCDIR}/images ${PKGMANDIR}/man1

MAKE_ENV+=		PERL5=${PERL5:Q}
INSTALL_ENV+=		mkinstalldirs=${INSTALL_DATA_DIR:Q}

post-install:
	${INSTALL_DATA} ${BUILD_DIRS:Q}/README.postgis ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/html/postgis.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/html/style.css ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/html/images/* ${DESTDIR}${DOCDIR}/images
	${INSTALL_MAN} ${BUILD_DIRS:Q}/doc/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/postgis_comments.sql ${DESTDIR}${PREFIX}/share/postgresql/contrib/postgis-1.5

# TEST_DEPENDS
# .include "../../devel/cunit/buildlink3.mk"

.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
