# $NetBSD: Makefile,v 1.10 2004/04/25 01:04:57 snj Exp $

DISTNAME=	dvdview-1.2.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/data/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/
COMMENT=	Software only MPEG-1/2 video decoder

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES
USE_BUILDLINK3=	yes

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
MAKE_ENV+=	RTLIB=-lrt
.else
MAKE_ENV+=	RTLIB=
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dvdview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dvdview

.include "../../graphics/libvideogfx/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
