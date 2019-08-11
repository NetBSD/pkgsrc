# $NetBSD: Makefile,v 1.133 2019/08/11 17:54:31 adam Exp $

DISTNAME=	mkvtoolnix-36.0.0
CATEGORIES=	multimedia
MASTER_SITES=	https://mkvtoolnix.download/sources/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mkvtoolnix.download/
COMMENT=	Set of tools to create, alter and inspect Matroska files
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=	po4a-[0-9]*:../../textproc/po4a
BUILD_DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}

USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-optimization
CONFIGURE_ARGS+=	--disable-precompiled-headers
CONFIGURE_ARGS+=	--disable-update-check
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--with-boost-date-time=boost_date_time
CONFIGURE_ARGS+=	--with-boost-filesystem=boost_filesystem
CONFIGURE_ARGS+=	--with-boost_regex=boost_regex
CONFIGURE_ARGS+=	--with-boost-system=boost_system
CONFIGURE_ARGS+=	--with-docbook-xsl-root=${PREFIX}/share/xsl/docbook

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
BUILDLINK_ABI_DEPENDS.libebml+= libebml>=1.3.5
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/cmark/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
