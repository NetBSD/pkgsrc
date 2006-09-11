# $NetBSD: Makefile,v 1.55 2006/09/11 18:53:16 wiz Exp $

DISTNAME=	fontconfig-2.4.0
CATEGORIES=	fonts
MASTER_SITES=	http://www.fontconfig.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fontconfig.org/
COMMENT=	Library for configuring and customizing font access

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
CONF_FILES+=	${EGDIR}/conf.d/20-fix-globaladvance.conf ${PKG_SYSCONFDIR}/conf.d/20-fix-globaladvance.conf
CONF_FILES+=	${EGDIR}/conf.d/20-lohit-gujarati.conf ${PKG_SYSCONFDIR}/conf.d/20-lohit-gujarati.conf
CONF_FILES+=	${EGDIR}/conf.d/20-unhint-small-vera.conf ${PKG_SYSCONFDIR}/conf.d/20-unhint-small-vera.conf
CONF_FILES+=	${EGDIR}/conf.d/30-amt-aliases.conf ${PKG_SYSCONFDIR}/conf.d/30-amt-aliases.conf
CONF_FILES+=	${EGDIR}/conf.d/30-urw-aliases.conf ${PKG_SYSCONFDIR}/conf.d/30-urw-aliases.conf
CONF_FILES+=	${EGDIR}/conf.d/40-generic.conf ${PKG_SYSCONFDIR}/conf.d/40-generic.conf
CONF_FILES+=	${EGDIR}/conf.d/49-sansserif.conf ${PKG_SYSCONFDIR}/conf.d/49-sansserif.conf
CONF_FILES+=	${EGDIR}/conf.d/50-user.conf ${PKG_SYSCONFDIR}/conf.d/50-user.conf
CONF_FILES+=	${EGDIR}/conf.d/51-local.conf ${PKG_SYSCONFDIR}/conf.d/51-local.conf
CONF_FILES+=	${EGDIR}/conf.d/60-latin.conf ${PKG_SYSCONFDIR}/conf.d/60-latin.conf
CONF_FILES+=	${EGDIR}/conf.d/65-fonts-persian.conf ${PKG_SYSCONFDIR}/conf.d/65-fonts-persian.conf
CONF_FILES+=	${EGDIR}/conf.d/65-nonlatin.conf ${PKG_SYSCONFDIR}/conf.d/65-nonlatin.conf
CONF_FILES+=	${EGDIR}/conf.d/69-unifont.conf ${PKG_SYSCONFDIR}/conf.d/69-unifont.conf
CONF_FILES+=	${EGDIR}/conf.d/80-delicious.conf ${PKG_SYSCONFDIR}/conf.d/80-delicious.conf
CONF_FILES+=	${EGDIR}/conf.d/90-synthetic.conf ${PKG_SYSCONFDIR}/conf.d/90-synthetic.conf

LIBS+=		${BUILDLINK_LDADD.iconv}

TEST_TARGET=	check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
