# $NetBSD: Makefile,v 1.73 2011/11/01 06:01:12 sbd Exp $

DISTNAME=	fontconfig-2.8.0
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	http://www.fontconfig.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fontconfig.org/
COMMENT=	Library for configuring and customizing font access
#LICENSE=	x11?

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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
CONFIGURE_ARGS+=	--with-cache-dir=${VARBASE:Q}/cache/fontconfig
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--enable-docs
CONFIGURE_ENV+=		HASDOCBOOK=no

.include "../../mk/bsd.prefs.mk"

GSFONTS=	${PREFIX}/share/fonts/urw,${PREFIX}/share/ghostscript/fonts
.if ${X11BASE} != ${LOCALBASE}
CONFIGURE_ARGS+=	--with-add-fonts=${X11BASE}/lib/X11/fonts,${GSFONTS}
.else
CONFIGURE_ARGS+=	--with-add-fonts=${GSFONTS}
.endif

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-arch=${MACHINE_ARCH}
.endif

EGDIR=		${PREFIX}/share/examples/fontconfig
CONF_FILES=	${EGDIR}/fonts.conf ${PKG_SYSCONFDIR}/fonts.conf
CONF_FILES+=	${EGDIR}/fonts.dtd ${PKG_SYSCONFDIR}/fonts.dtd
MAKE_DIRS+=	${PKG_SYSCONFDIR}/conf.d
CONF_FILES+=	${EGDIR}/conf.d/20-fix-globaladvance.conf ${PKG_SYSCONFDIR}/conf.d/20-fix-globaladvance.conf
CONF_FILES+=	${EGDIR}/conf.d/20-unhint-small-vera.conf ${PKG_SYSCONFDIR}/conf.d/20-unhint-small-vera.conf
CONF_FILES+=	${EGDIR}/conf.d/30-metric-aliases.conf ${PKG_SYSCONFDIR}/conf.d/30-metric-aliases.conf
CONF_FILES+=	${EGDIR}/conf.d/30-urw-aliases.conf ${PKG_SYSCONFDIR}/conf.d/30-urw-aliases.conf
CONF_FILES+=	${EGDIR}/conf.d/40-nonlatin.conf ${PKG_SYSCONFDIR}/conf.d/40-nonlatin.conf
CONF_FILES+=	${EGDIR}/conf.d/45-latin.conf ${PKG_SYSCONFDIR}/conf.d/45-latin.conf
CONF_FILES+=	${EGDIR}/conf.d/49-sansserif.conf ${PKG_SYSCONFDIR}/conf.d/49-sansserif.conf
CONF_FILES+=	${EGDIR}/conf.d/50-user.conf ${PKG_SYSCONFDIR}/conf.d/50-user.conf
CONF_FILES+=	${EGDIR}/conf.d/51-local.conf ${PKG_SYSCONFDIR}/conf.d/51-local.conf
CONF_FILES+=	${EGDIR}/conf.d/60-latin.conf ${PKG_SYSCONFDIR}/conf.d/60-latin.conf
CONF_FILES+=	${EGDIR}/conf.d/65-fonts-persian.conf ${PKG_SYSCONFDIR}/conf.d/65-fonts-persian.conf
CONF_FILES+=	${EGDIR}/conf.d/65-nonlatin.conf ${PKG_SYSCONFDIR}/conf.d/65-nonlatin.conf
CONF_FILES+=	${EGDIR}/conf.d/69-unifont.conf ${PKG_SYSCONFDIR}/conf.d/69-unifont.conf
CONF_FILES+=	${EGDIR}/conf.d/80-delicious.conf ${PKG_SYSCONFDIR}/conf.d/80-delicious.conf
CONF_FILES+=	${EGDIR}/conf.d/90-synthetic.conf ${PKG_SYSCONFDIR}/conf.d/90-synthetic.conf
CONF_FILES+=	${EGDIR}/conf.d/30-pkgsrc-aliases.conf ${PKG_SYSCONFDIR}/conf.d/30-pkgsrc-aliases.conf

MAKE_DIRS+=	${VARBASE}/cache
BUILD_DEFS+=	VARBASE

LIBS+=		${BUILDLINK_LDADD.iconv}

TEST_TARGET=	check

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=	CC_FOR_BUILD=${NATIVE_CC:Q}
.endif

pre-configure:
	${ECHO} '#define FC_ARCHITECTURE "@host_cpu@"' > ${WRKSRC}/fc-arch/fcarch.h.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/30-pkgsrc-aliases.conf \
		${DESTDIR}${EGDIR}/conf.d

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
