# $NetBSD: Makefile,v 1.1 2014/02/02 15:24:13 rodent Exp $

DISTNAME=	smpeg2-2.0.0
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

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
