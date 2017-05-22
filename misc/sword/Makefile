# $NetBSD: Makefile,v 1.12 2017/05/22 23:40:42 joerg Exp $
#

DISTNAME=	sword-1.7.4
PKGREVISION=	10
CATEGORIES=	misc
MASTER_SITES=	http://www.crosswire.org/ftpmirror/pub/sword/source/v1.7/

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	http://www.crosswire.org/sword/index.jsp
COMMENT=	SWORD Bible study software libraries and tools
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++11

CONFIGURE_ARGS+=	--with-clucene=${BUILDLINK_PREFIX.libclucene}

PKGCONFIG_OVERRIDE+=	sword.pc.in

INSTALLATION_DIRS+=share/examples/sword
INSTALL_TARGET= install install_config
REQD_FILES=	${PREFIX}/share/examples/sword/sword.conf \
		${PKG_SYSCONFDIR}/sword.conf

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
