# $NetBSD: Makefile,v 1.54 2006/07/23 01:09:11 minskim Exp $

DISTNAME=	fontconfig-2.3.2
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	http://www.fontconfig.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fontconfig.org/
COMMENT=	Library for configuring and customizing font access

PATCH_SITES=    http://www.freetype.org/freetype2/patches/
PATCHFILES=	fontconfig-2.3.2-noftinternals.patch
PATCH_DIST_STRIP=	-p1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE=	fontconfig.pc.in

PKG_SYSCONFSUBDIR=	fontconfig

CONFIGURE_ARGS+=	--with-default-fonts=${LOCALBASE}/lib/X11/fonts
CONFIGURE_ARGS+=	--with-freetype-config=${BUILDLINK_PREFIX.freetype2}/bin/freetype-config
CONFIGURE_ARGS+=	--with-expat-includes=${BUILDLINK_PREFIX.expat}/include
CONFIGURE_ARGS+=	--with-expat-lib=${BUILDLINK_PREFIX.expat}/lib
CONFIGURE_ARGS+=	--with-confdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--enable-docs
CONFIGURE_ENV+=		HASDOCBOOK=no

.include "../../mk/bsd.prefs.mk"

.if (${X11BASE} != ${LOCALBASE})
CONFIGURE_ARGS+=	--with-add-fonts=${X11BASE}/lib/X11/fonts
.endif

EGDIR=		${PREFIX}/share/examples/fontconfig
CONF_FILES=	${EGDIR}/fonts.conf ${PKG_SYSCONFDIR}/fonts.conf
CONF_FILES+=	${EGDIR}/fonts.dtd ${PKG_SYSCONFDIR}/fonts.dtd
MAKE_DIRS+=	${PKG_SYSCONFDIR}/conf.d
CONF_FILES+=	${EGDIR}/conf.d/autohint.conf ${PKG_SYSCONFDIR}/conf.d/autohint.conf
CONF_FILES+=	${EGDIR}/conf.d/no-bitmaps.conf ${PKG_SYSCONFDIR}/conf.d/no-bitmaps.conf
CONF_FILES+=	${EGDIR}/conf.d/no-sub-pixel.conf ${PKG_SYSCONFDIR}/conf.d/no-sub-pixel.conf
CONF_FILES+=	${EGDIR}/conf.d/sub-pixel.conf ${PKG_SYSCONFDIR}/conf.d/sub-pixel.conf
CONF_FILES+=	${EGDIR}/conf.d/unhinted.conf ${PKG_SYSCONFDIR}/conf.d/unhinted.conf
CONF_FILES+=	${EGDIR}/conf.d/yes-bitmaps.conf ${PKG_SYSCONFDIR}/conf.d/yes-bitmaps.conf

LIBS+=		${BUILDLINK_LDADD.iconv}

TEST_TARGET=	check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
