# $NetBSD: Makefile,v 1.77 2016/03/13 09:36:58 taca Exp $

DISTNAME=	mkvtoolnix-5.0.1
PKGREVISION=	27
CATEGORIES=	multimedia
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/mkvtoolnix/
COMMENT=	Set of tools to create, alter and inspect Matroska files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ARGS+=	--with-boost_regex=boost_regex
CONFIGURE_ARGS+=	--with-boost-system=boost_system
CONFIGURE_ARGS+=	--with-boost-filesystem=boost_filesystem

REPLACE_LOCALEDIR_PATTERNS=	build-config.in

LDFLAGS.DragonFly=	-lboost_system
LDFLAGS.SunOS+=		-lintl

INSTALL_ENV+=	SHELL=${SH:Q}

.include "../../mk/bsd.prefs.mk"

.if !empty(MAKE_JOBS)
DRAKE_ARGS=	-j${MAKE_JOBS}
.else
DRAKE_ARGS=	# empty
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ruby drake ${DRAKE_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ruby drake install

.include "options.mk"

.if ${OPSYS} != "Darwin"
.include "../../lang/ruby/buildlink3.mk"
BUILDLINK_DEPMETHOD.${RUBY_BASE}=	build
.endif

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
