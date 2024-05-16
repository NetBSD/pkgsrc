# $NetBSD: Makefile,v 1.28 2024/05/16 21:31:47 riastradh Exp $

DISTNAME=	pkgconf-2.2.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://distfiles.dereferenced.org/pkgconf/

MAINTAINER=	nico@orgrim.net
HOMEPAGE=	https://github.com/pkgconf/pkgconf
COMMENT=	API-driven pkg-config replacement
LICENSE=	modified-bsd

CONFLICTS+=	pkg-config-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-system-libdir=/usr/lib
CONFIGURE_ARGS+=	--with-system-includedir=/usr/include

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

PKGCONFIG_PATHS=	${PREFIX}/lib/pkgconfig
PKGCONFIG_PATHS+=	${PREFIX}/share/pkgconfig
PKGCONFIG_PATHS+=	/usr/lib/pkgconfig

# for reallocarray
# https://github.com/pkgconf/pkgconf/issues/285
CPPFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

.include "../../mk/bsd.prefs.mk"

.if ${LOCALBASE} != ${X11BASE}
PKGCONFIG_PATHS+=	${X11BASE}/lib/pkgconfig
.endif

CONFIGURE_ARGS+=	--with-pkg-config-dir=${PKGCONFIG_PATHS:ts::Q}

# configure script incorrectly sets only _FILE_OFFSET_BITS=64
CPPFLAGS.SunOS+=	-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE

post-install:
	${LN} -s pkgconf ${DESTDIR}${PREFIX}/bin/pkg-config
	${LN} -s pkgconf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pkg-config.1

.include "../../mk/bsd.pkg.mk"
