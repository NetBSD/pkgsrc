# $NetBSD: Makefile,v 1.14 2016/02/25 15:49:43 jperkin Exp $

DISTNAME=	dvdview-1.2.2
PKGREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/
COMMENT=	Software only MPEG-1/2 video decoder

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_ENV.SunOS+=	RTLIB=-lrt
MAKE_ENV.*+=		RTLIB=

INSTALLATION_DIRS+=	share/doc/dvdview

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dvdview

.include "../../graphics/libvideogfx/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
