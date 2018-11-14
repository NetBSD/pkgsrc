# $NetBSD: Makefile,v 1.269 2018/11/14 22:21:27 kleink Exp $

DISTNAME=		gnucash-3.3
PKGREVISION=		5
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnucash/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal or business finance management program
LICENSE=		gnu-gpl-v3

DEPENDS+=		guile22-slib>=3.2.1:../../devel/guile22-slib
DEPENDS+=		p5-Finance-Quote-[0-9]*:../../finance/p5-Finance-Quote
DEPENDS+=		p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=		dconf-[0-9]*:../../devel/dconf
# instead of USE_TOOLS+=msgfmt, since we need a newer version
TOOL_DEPENDS+=		gettext-tools>=0.19.6:../../devel/gettext-tools

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes
USE_TOOLS+=		perl:run pkg-config
# remove when using ninja
USE_TOOLS+=		gmake

# build failure in test-tx_import and a couple test failures
# https://bugzilla.gnome.org/show_bug.cgi?id=795251
TEST_TARGET=		check

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/gnucash
CXXFLAGS+=		-Wno-deprecated-declarations

MAKE_ENV+=		GUILE_AUTO_COMPILE=0
CMAKE_ARGS+=		-DWITH_AQBANKING=OFF
CMAKE_ARGS+=		-DPERL_EXECUTABLE=${PERL5}
CMAKE_ARGS+=		-DCOMPILE_GSCHEMAS=OFF
#CMAKE_ARGS+=		-GNinja
#BUILD_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

#do-build:
#	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ninja
#do-install:
#	cd ${WRKSRC}; ${SETENV} ${INSTALL_ENV} ninja install

REPLACE_PERL+=		common/gnc-test-env.pl
REPLACE_PERL+=		libgnucash/backend/xml/test/grab-types.pl
REPLACE_PERL+=		libgnucash/quotes/gnc-fq-dump
REPLACE_PERL+=		util/elegant-sort.pl

PLIST_SRC=		PLIST

PKG_SYSCONFSUBDIR=	gnucash
CONF_FILES+=		${PREFIX}/share/examples/gnucash/environment ${PKG_SYSCONFDIR}/environment
INSTALLATION_DIRS=	share/examples/gnucash

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/gnucash/environment ${DESTDIR}${PREFIX}/share/examples/gnucash/environment

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.40.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-headers+=   boost-headers>=1.64.0nb3
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/guile22/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
