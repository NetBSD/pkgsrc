# $NetBSD: Makefile,v 1.54 2018/11/20 18:16:15 gdt Exp $

MAJOR=		2.5
DISTNAME=	postgis-${MAJOR}.1
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases geography
MASTER_SITES=	https://download.osgeo.org/postgis/source/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://postgis.net/
COMMENT=	Spatial database capabilities for PostgreSQL

LICENSE=	gnu-gpl-v2

# Needs 9.4 or higher
PGSQL_VERSIONS_ACCEPTED=	10 96 95 94

DEPENDS+=		postgresql${PGSQL_VERSION}-server-[0-9]*:../../databases/postgresql${PGSQL_VERSION}-server
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

CONFLICTS=		postgis-[0-9]*

# TODO section
# 1. Fix installation use of "install -o root" from pgxs.mk, when postgresql
#    was built as root and postgis is built/installed as a non-root user.
#    https://lists.osgeo.org/pipermail/postgis-devel/2015-July/025045.html
# 2. Recheck and fix or file upstream about MAKE_JOBS_SAFE.
# 3. Check 2nd make, and file bug about anything that happens.  Check xsltproc
#    in particular.

# gmake complains about adding + to parent rule
MAKE_JOBS_SAFE=		no


USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++ c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake lex pax perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/postgresql/contrib

# The address standardizer needs more modules; see
# share/doc/postgresql/extension/README.address_standardizer
# for details.  Until they are required, disable it to ensure
# repeatable builds.
CONFIGURE_ARGS+=	--without-address-standardizer

BUILD_TARGET=		all docs
INSTALL_TARGET=		install docs-install

DOCDIR=			${PREFIX}/share/doc/postgis

PLIST_SUBST+=		MAJOR=${MAJOR}
PRINT_PLIST_AWK+=	{ gsub(/postgis-${MAJOR:S|/|\\/|g}/, "postgis-$${MAJOR}") }
PRINT_PLIST_AWK+=	{ gsub(/topology-${MAJOR:S|/|\\/|g}/, "topology-$${MAJOR}") }

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	extras/template_gis/profile \
			extras/template_gis/createdb.postgis.1 \
			extras/template_gis/mktemplate_gis.1 \
			extras/template_gis/postgis_env.sh.in
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	${DOCDIR} ${DOCDIR}/images ${PKGMANDIR}/man1

REPLACE_PERL+=		utils/postgis_restore.pl.in
REPLACE_PERL+=		utils/create_spatial_ref_sys_config_dump.pl
#MAKE_ENV+=		PERL5=${PERL5:Q}

INSTALL_ENV+=		mkinstalldirs=${INSTALL_DATA_DIR:Q}

TEST_TARGET=		check

# TEST_DEPENDS
.include "../../devel/cunit/buildlink3.mk"

# DOC DEPENDS
CONFIGURE_ARGS+=	-with-xsldir=${PREFIX}/share/xsl/docbook
# By default xsltproc downloads DTDs.  postgis tells it not to, but
# the dependencies are not packaged.  The timing option, not needed,
# is to make the variable non-empty, to work around a
# defined/non-empty incorrect test in postgis.
MAKE_ENV+=		"XSLTPROCFLAGS=--timing"

# These are really all BUILD_DEPENDS.
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

# NORMAL DEPENDS
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
