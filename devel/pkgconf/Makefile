# $NetBSD: Makefile,v 1.6 2016/02/04 11:50:54 wiz Exp $

DISTNAME=	pkgconf-0.9.12.20151211
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://rabbit.dereferenced.org/~nenolod/distfiles/
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nico@orgrim.net
HOMEPAGE=	https://github.com/pkgconf/pkgconf
COMMENT=	API-driven pkg-config replacement
LICENSE=	modified-bsd

CONFLICTS+=	pkg-config-[0-9]*

WRKSRC=		${WRKDIR}/pkgconf-1.0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkg-config-dir=${PREFIX}/lib/pkgconfig:${PREFIX}/share/pkgconfig:/usr/lib/pkgconfig \
		--with-system-libdir=/usr/lib \
		--with-system-includedir=/usr/include
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1

post-install:
	${LN} -s ${PREFIX}/bin/pkgconf ${DESTDIR}${PREFIX}/bin/pkg-config

.include "../../mk/bsd.pkg.mk"
