# $NetBSD: Makefile,v 1.187 2021/12/29 17:01:18 adam Exp $

DISTNAME=	mkvtoolnix-64.0.0
CATEGORIES=	multimedia
MASTER_SITES=	https://mkvtoolnix.download/sources/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mkvtoolnix.download/
COMMENT=	Set of tools to create, alter and inspect Matroska files
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	docbook-xsl>=1.79.1nb5:../../textproc/docbook-xsl
BUILD_DEPENDS+=	po4a-[0-9]*:../../textproc/po4a
BUILD_DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}

# 'The following features of the C++17 standards are not supported by c++:
#  * file system library (C++17)
# If you are using the GNU C compiler collection (gcc), you need
# at least v8; for clang v7 and newer should work.'
GCC_REQD+=	8

USE_LANGUAGES=		c c++17
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-optimization
CONFIGURE_ARGS+=	--disable-precompiled-headers
CONFIGURE_ARGS+=	--disable-update-check
CONFIGURE_ARGS+=	--enable-qt5
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--with-docbook-xsl-root=${PREFIX}/share/xsl/docbook
CONFIGURE_ARGS+=	--with-qmake=${QTDIR}/bin/qmake

REPLACE_LOCALEDIR_PATTERNS=	build-config.in

LDFLAGS.DragonFly=	-lboost_system
LDFLAGS.SunOS+=		-lintl

INSTALL_ENV+=	SHELL=${SH:Q}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RAKE}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${RAKE} install

.include "options.mk"

.include "../../lang/ruby/rubyversion.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.libebml+= libebml>=1.4.2
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmatroska+= libmatroska>=1.6.3
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/cmark/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../textproc/utf8-cpp/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
