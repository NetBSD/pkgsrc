# $NetBSD: Makefile,v 1.318 2022/06/28 09:27:42 wiz Exp $

DISTNAME=		gnucash-4.11
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_GITHUB:=gnucash/}
EXTRACT_SUFX=		.tar.bz2
GITHUB_RELEASE=		${PKGVERSION_NOREV}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal or business finance management program
LICENSE=		gnu-gpl-v3

DEPENDS+=		guile30-slib>=3.2.1:../../devel/guile30-slib
DEPENDS+=		p5-Finance-Quote-[0-9]*:../../finance/p5-Finance-Quote
DEPENDS+=		p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=		dconf-[0-9]*:../../devel/dconf

GCC_REQD+=		8
USE_LANGUAGES=		c c++17
USE_CMAKE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes
USE_TOOLS+=		bash perl:run pkg-config
USE_TOOLS+=		gmake

# build failure in test-tx_import and a couple test failures
# https://bugzilla.gnome.org/show_bug.cgi?id=795251
TEST_TARGET=		check

# too fragile
BUILDLINK_TRANSFORM+=	rm:-Werror

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/gnucash
CXXFLAGS+=		-Wno-deprecated-declarations
# https://bugs.gnucash.org/show_bug.cgi?id=797039
CFLAGS+=		-Wno-char-subscripts

MAKE_ENV+=		GUILE_AUTO_COMPILE=0
CMAKE_ARGS+=		-DWITH_AQBANKING=OFF
CMAKE_ARGS+=		-DPERL_EXECUTABLE=${PERL5}
CMAKE_ARGS+=		-DCOMPILE_GSCHEMAS=OFF

# test status as of 4.9
# 22 test failures, 17 after "paxctl +m ${WRKSRC}/bin/*"
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/lib
REPLACE_PERL+=		common/gnc-test-env.pl
REPLACE_PERL+=		libgnucash/backend/xml/test/grab-types.pl
REPLACE_PERL+=		util/elegant-sort.pl

PLIST_SRC=		PLIST

PKG_SYSCONFSUBDIR=	gnucash
CONF_FILES+=		${PREFIX}/share/examples/gnucash/environment ${PKG_SYSCONFDIR}/environment
INSTALLATION_DIRS=	share/examples/gnucash

.include "../../mk/bsd.prefs.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/gnucash/environment ${DESTDIR}${PREFIX}/share/examples/gnucash/environment
.if ${OPSYS} == "NetBSD"
# needed for JIT of guile30 as of guile30-3.0.7
	/usr/sbin/paxctl +m ${DESTDIR}${PREFIX}/bin/gnucash
.endif

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.56.1
.include "../../devel/glib2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-headers+=   boost-headers>=1.67
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.googletest+=	googletest>=1.8.0
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/swig3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/guile30/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.9.4
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=2.14.1
.include "../../www/webkit-gtk/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22.30
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
