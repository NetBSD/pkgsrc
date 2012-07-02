# $NetBSD: Makefile,v 1.13 2012/07/02 13:37:36 adam Exp $
#

DISTNAME=	exempi-2.1.1
PKGREVISION=	5
CATEGORIES=	devel graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libopenraw.freedesktop.org/wiki/Exempi
COMMENT=	XMP library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_tls=none
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	LIBS=${BUILDLINK_LDADD.iconv:Q}

PKGCONFIG_OVERRIDE+=	exempi/exempi-2.0.pc.in

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
