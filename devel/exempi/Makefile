# $NetBSD: Makefile,v 1.33 2018/12/13 19:51:47 adam Exp $

DISTNAME=	exempi-2.3.0
PKGREVISION=	8
CATEGORIES=	devel graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libopenraw.freedesktop.org/wiki/Exempi
COMMENT=	XMP (Extensible Metadata Platform) library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_tls=none
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++03

CONFIGURE_ARGS+=	LIBS=${BUILDLINK_LDADD.iconv:Q}

PTHREAD_AUTO_VARS=	yes

PKGCONFIG_OVERRIDE+=	exempi/exempi-2.0.pc.in

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
