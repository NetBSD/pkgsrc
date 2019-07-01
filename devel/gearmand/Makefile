# $NetBSD: Makefile,v 1.39 2019/07/01 04:07:47 ryoon Exp $

DISTNAME=	gearmand-1.1.18
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gearman/}
GITHUB_PROJECT= gearmand
GITHUB_RELEASE= ${PKGVERSION_NOREV}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	http://gearman.org/
COMMENT=	Gearman C Server and Library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c gnu++03

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
