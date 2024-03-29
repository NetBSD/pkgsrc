# $NetBSD: Makefile,v 1.69 2023/12/29 18:24:41 adam Exp $

DISTNAME=	gearmand-1.1.19.1
PKGREVISION=	17
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gearman/}
GITHUB_PROJECT=	gearmand
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gearman.org/
COMMENT=	Gearman C Server and Library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

FORCE_CXX_STD=	gnu++11

CONFIGURE_ARGS+=	--enable-jobserver=no
CONFIGURE_ARGS+=	--disable-libdrizzle
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}

CONFIGURE_ENV.SunOS+=	ax_cv_check_cflags__Werror__pie=no
CONFIGURE_ENV.SunOS+=	ax_cv_check_cxxflags__Werror__pie=no

.include "options.mk"

PKGCONFIG_OVERRIDE+=	support/gearmand.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
