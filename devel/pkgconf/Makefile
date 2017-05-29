# $NetBSD: Makefile,v 1.11 2017/05/29 13:23:41 wiz Exp $

DISTNAME=	pkgconf-1.3.5
CATEGORIES=	devel
MASTER_SITES=	http://rabbit.dereferenced.org/~nenolod/distfiles/

MAINTAINER=	nico@orgrim.net
HOMEPAGE=	https://github.com/pkgconf/pkgconf
COMMENT=	API-driven pkg-config replacement
LICENSE=	modified-bsd

CONFLICTS+=	pkg-config-[0-9]*

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-system-libdir=/usr/lib \
		--with-system-includedir=/usr/include
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

PKGCONFIG_PATHS=	${PREFIX}/lib/pkgconfig
PKGCONFIG_PATHS+=	${PREFIX}/share/pkgconfig
PKGCONFIG_PATHS+=	/usr/lib/pkgconfig

.if ${LOCALBASE} != ${X11BASE}
PKGCONFIG_PATHS+=	${X11BASE}/lib/pkgconfig
.endif

CONFIGURE_ARGS+=	--with-pkg-config-dir='${PKGCONFIG_PATHS:ts::Q}'

post-install:
	${LN} -s ${DESTDIR}${PREFIX}/bin/pkgconf ${DESTDIR}${PREFIX}/bin/pkg-config

.include "../../mk/bsd.pkg.mk"
