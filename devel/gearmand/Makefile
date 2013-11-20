# $NetBSD: Makefile,v 1.4 2013/11/20 20:04:36 adam Exp $
#

DISTNAME=	gearmand-1.0.6
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/gearmand/1.0/1.0.6/+download/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://gearman.org/
COMMENT=	Gearman C Server and Library
LICENSE=	modified-bsd
FETCH_USING=	curl

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--enable-jobserver=no
CONFIGURE_ARGS+=	--disable-libdrizzle

.include "options.mk"

PKGCONFIG_OVERRIDE+=	support/gearmand.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
