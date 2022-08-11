# $NetBSD: Makefile,v 1.13 2022/08/11 05:09:07 gutteridge Exp $

DISTNAME=	smpeg2-2.0.0
PKGREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	http://www.libsdl.org/projects/smpeg/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/smpeg/
COMMENT=	Free MPEG1 video player library with sound support
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--program-suffix=2

.include "../../mk/bsd.fast.prefs.mk"

LDFLAGS.SunOS+=	-lsocket -lnsl

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/smpeg2-config2 \
		${DESTDIR}${PREFIX}/bin/smpeg2-config

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
