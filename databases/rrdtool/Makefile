# $NetBSD: Makefile,v 1.132 2018/11/12 03:51:08 ryoon Exp $

PKGREVISION= 4
.include "Makefile.common"

DEPENDS+=		dejavu-ttf>=2.26:../../fonts/dejavu-ttf

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config perl msgfmt intltool groff nroff
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-libdbi
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-perl-options=${MAKE_PARAMS:Q}

PTHREAD_OPTS+=		require
PERL5_CONFIGURE=	no
PERL5_PACKLIST+=	auto/RRDp/.packlist
PERL5_PACKLIST+=	auto/RRDs/.packlist

# rrdtool explicitly forbids any use of -ffast-math
BUILDLINK_TRANSFORM+=	rm:-ffast-math

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-build
SUBST_MESSAGE.prefix=	Fixing $${prefix} in scripts.
SUBST_FILES.prefix=	examples/cgi-demo.cgi
SUBST_SED.prefix=	-e '1s,^\#! \$${prefix},\#! ${PREFIX},'

TEST_TARGET=		check

RCD_SCRIPTS=		rrdcached

# rrd_config.h is needed for databases/ruby-rrdtool
post-install:
	${INSTALL_DATA} ${WRKSRC}/src/rrd_config.h ${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

RRDCACHED_USER?=	rrdcached
RRDCACHED_GROUP?=	${RRDCACHED_USER}

PKG_USERS_VARS=		RRDCACHED_USER
PKG_GROUPS_VARS=	RRDCACHED_GROUP
PKG_GROUPS=		${RRDCACHED_GROUP}
PKG_USERS=		${RRDCACHED_USER}:${RRDCACHED_GROUP}
PKG_GECOS.${RRDCACHED_USER}=	RRDCacheD daemon user

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so
PLIST_SUBST+=		SOEXT=${SOEXT}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
