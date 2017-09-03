# $NetBSD: Makefile,v 1.92 2017/09/03 08:53:11 wiz Exp $

DISTNAME=	mkvtoolnix-9.5.0
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	https://mkvtoolnix.download/sources/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mkvtoolnix.download/
COMMENT=	Set of tools to create, alter and inspect Matroska files
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-curl --disable-precompiled-headers
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--with-boost_regex=boost_regex
CONFIGURE_ARGS+=	--with-boost-system=boost_system
CONFIGURE_ARGS+=	--with-boost-filesystem=boost_filesystem
CONFIGURE_ARGS+=	--disable-optimization

REPLACE_LOCALEDIR_PATTERNS=	build-config.in

LDFLAGS.DragonFly=	-lboost_system
LDFLAGS.SunOS+=		-lintl

INSTALL_ENV+=	SHELL=${SH:Q}

.if !empty(MAKE_JOBS)
DRAKE_ARGS=	-j${MAKE_JOBS}
.else
DRAKE_ARGS=	# empty
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/${RAKE_NAME} ${DRAKE_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${LOCALBASE}/bin/${RAKE_NAME} install

.include "options.mk"

.include "../../lang/ruby/rubyversion.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.libebml+= libebml>=1.2.2
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
