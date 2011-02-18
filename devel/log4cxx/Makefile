# $NetBSD: Makefile,v 1.2 2011/02/18 18:00:43 reed Exp $

DISTNAME=	apache-log4cxx-0.10.0
PKGNAME=	${DISTNAME:S/apache-//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=logging/log4cxx/0.10.0/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://logging.apache.org/log4cxx/
COMMENT=	Logging framework for C++

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
# c for configure
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-doxygen --disable-html-docs

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	liblog4cxx.pc.in

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
