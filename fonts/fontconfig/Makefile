# $NetBSD: Makefile,v 1.132 2023/12/30 10:21:52 wiz Exp $

DISTNAME=	fontconfig-2.15.0
CATEGORIES=	fonts
MASTER_SITES=	https://www.fontconfig.org/release/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fontconfig.org/
COMMENT=	Library for configuring and customizing font access
#LICENSE=	x11?

# https://bugs.freedesktop.org/show_bug.cgi?id=101280
TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-default-fonts=${PREFIX}/share/fonts/X11
CONFIGURE_ARGS+=	--with-expat-includes=${BUILDLINK_PREFIX.expat}/include
CONFIGURE_ARGS+=	--with-expat-lib=${BUILDLINK_PREFIX.expat}/lib
CONFIGURE_ARGS+=	--with-baseconfigdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-cache-dir=${VARBASE}/cache/fontconfig
CONFIGURE_ARGS+=	--enable-docs
CONFIGURE_ENV+=		HASDOCBOOK=no

PKGCONFIG_OVERRIDE=	fontconfig.pc.in

PKG_SYSCONFSUBDIR=	fontconfig

.include "../../mk/compiler.mk"
# Workaround for GCC 4.2 bug, http://gcc.gnu.org/bugzilla/show_bug.cgi?id=46861
# GCC 4.2 and -fPIC with visibility
.if ${CC_VERSION:Mgcc-4.2.*}
SUBST_CLASSES+=			visibility
SUBST_STAGE.visibility=		pre-configure
SUBST_MESSAGE.visibility=	Removing visibility
SUBST_FILES.visibility=		src/makealias
SUBST_SED.visibility=		-e 's/__attribute((visibility("hidden")))//g'
SUBST_SED.visibility+=		-e 's/, visibility("default")//g'
.endif

.include "../../mk/bsd.prefs.mk"

ADDFONTS=	${PREFIX}/share/fonts/urw,${PREFIX}/share/ghostscript/fonts,${PREFIX}/share/fonts/X11
.if ${X11BASE} != ${LOCALBASE}
ADDFONTS:=	${X11BASE}/lib/X11/fonts,${ADDFONTS}
.else
ADDFONTS:=	${LOCALBASE}/share/fonts/X11,${ADDFONTS}
.endif

.if ${OPSYS} == "Darwin"
ADDFONTS:=		~/Library/Fonts,/Library/Fonts,/System/Library/Fonts,${ADDFONTS}
CONFIGURE_ARGS+=	--with-arch=${MACHINE_ARCH}
.endif
CONFIGURE_ARGS+=	--with-add-fonts=${ADDFONTS}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-build
SUBST_FILES.prefix=	conf.d/README
SUBST_VARS.prefix=	PREFIX

EGDIR=		${PREFIX}/share/examples/fontconfig
CONF_FILES=	${EGDIR}/fonts.conf ${PKG_SYSCONFDIR}/fonts.conf
CONF_FILES+=	${EGDIR}/conf.d/README ${PKG_SYSCONFDIR}/conf.d/README

TMPLDIR=	${PREFIX}/share/fontconfig/conf.avail
MAKE_DIRS+=	${PKG_SYSCONFDIR}/conf.d
# following list from ${WRKSRC}/conf.d/Makefile.am
FC_STDCONF=	\
	10-hinting-full.conf	\
	10-scale-bitmap-fonts.conf \
	10-yes-antialias.conf	\
	10-sub-pixel-none.conf	\
	11-lcdfilter-default.conf \
	11-lcdfilter-none.conf \
	20-unhint-small-vera.conf \
	30-metric-aliases.conf \
	40-nonlatin.conf \
	45-generic.conf \
	45-latin.conf \
	48-spacing.conf \
	49-sansserif.conf \
	50-user.conf \
	51-local.conf \
	60-generic.conf \
	60-latin.conf \
	65-fonts-persian.conf \
	65-nonlatin.conf \
	69-unifont.conf \
	80-delicious.conf \
	90-synthetic.conf

# pkgsrc addition
FC_STDCONF+=	30-pkgsrc-aliases.conf
FC_STDCONF+=	70-no-bitmap-webfonts.conf
.for f in ${FC_STDCONF}
CONF_FILES+=	${TMPLDIR}/${f} ${PKG_SYSCONFDIR}/conf.d/${f}
.endfor

MAKE_DIRS+=	${VARBASE}/cache
BUILD_DEFS+=	VARBASE

TEST_TARGET=	check

.if ${USE_CROSS_COMPILE:U:tl} == yes
CONFIGURE_ENV+=	CC_FOR_BUILD=${NATIVE_CC:Q}
.endif

pre-configure:
	-cd ${BUILDLINK_X11_DIR:Q} && ${FIND} . -path "*fontconfig*" -type l -delete

post-install:
	${INSTALL_DATA} ${FILESDIR}/30-pkgsrc-aliases.conf ${DESTDIR}${TMPLDIR}
	${INSTALL_DATA} ${FILESDIR}/70-no-bitmap-webfonts.conf ${DESTDIR}${TMPLDIR}

.include "../../lang/python/tool.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
