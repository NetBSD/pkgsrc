# $NetBSD: Makefile,v 1.3 2015/02/09 08:43:13 snj Exp $

DISTNAME=	smpeg2-2.0.0
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.libsdl.org/projects/smpeg/release/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/smpeg/
COMMENT=	Free MPEG1 video player library with sound support
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	smpeg-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.fast.prefs.mk"

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
