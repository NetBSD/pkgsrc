# $NetBSD: Makefile,v 1.10 2014/04/01 13:51:56 fhajny Exp $
#

DISTNAME=	libmemcached-1.0.18
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

# Disable, the configure check is completely broken.
# Some checks are fixed in the local patches, but not enough to get
# an actual build running
.for sanitizer in address integer thread memory alignment bool bounds enum \
     float-cast-overflow float-divide-by-zero integer-divide-by-zero null \
     object-size return shift signed-integer-overflow unreachable \
     unsigned-integer-overflow vla-bound vptr
CONFIGURE_ARGS+=	ax_cv_check_cxxflags__Werror__fsanitize_${sanitizer:S/-/_/g}=no
CONFIGURE_ARGS+=	ax_cv_check_cflags__Werror__fsanitize_${sanitizer:S/-/_/g}=no
.endfor

post-configure:
	${ECHO} '#define HAVE_MEMCACHED_BINARY 1' >> ${WRKSRC}/mem_config.h
	${ECHO} '#define MEMCACHED_BINARY "${PREFIX}/bin/memcached"' >> ${WRKSRC}/mem_config.h

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
