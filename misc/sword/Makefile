# $NetBSD: Makefile,v 1.57 2024/05/29 16:33:40 adam Exp $
#

DISTNAME=	sword-1.9.0
PKGREVISION=	13
CATEGORIES=	misc
MASTER_SITES=	http://www.crosswire.org/ftpmirror/pub/sword/source/v${PKGVERSION_NOREV:R}/

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	https://www.crosswire.org/sword/index.jsp
COMMENT=	Bible study software libraries and tools
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++11

CONFIGURE_ARGS+=	--with-clucene=${BUILDLINK_PREFIX.libclucene}

PKGCONFIG_OVERRIDE+=	sword.pc.in

INSTALLATION_DIRS+=	share/examples/sword
INSTALL_TARGET=		install install_config
REQD_FILES=		${PREFIX}/share/examples/sword/sword.conf \
			${PKG_SYSCONFDIR}/sword.conf

# needed with at least GCC-5.4.0 which has a default value of 25
CXXFLAGS+=	-ftemplate-depth=50

# http://site.icu-project.org/download/61#TOC-Migration-Issues
CXXFLAGS+=	-DU_USING_ICU_NAMESPACE=1

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
