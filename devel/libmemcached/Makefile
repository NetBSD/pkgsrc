# $NetBSD: Makefile,v 1.7 2013/09/12 14:20:56 fhajny Exp $
#

DISTNAME=	libmemcached-1.0.17
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/libmemcached/1.0/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libmemcached.org/
COMMENT=	C/C++ client library and tools for the memcached server
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	support/libmemcached.pc.in

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CONFIGURE_ARGS+=--enable-jobserver=no

CPPFLAGS+=	-D__STDC_FORMAT_MACROS

LIBS.SunOS+=	-lsocket

post-configure:
	${ECHO} '#define HAVE_MEMCACHED_BINARY 1' >> ${WRKSRC}/mem_config.h
	${ECHO} '#define MEMCACHED_BINARY "${PREFIX}/bin/memcached"' >> ${WRKSRC}/mem_config.h

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
