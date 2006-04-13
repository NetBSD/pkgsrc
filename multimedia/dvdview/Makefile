# $NetBSD: Makefile,v 1.1.1.1 2006/04/13 20:15:50 wiz Exp $

DISTNAME=	dvdview-1.2.2
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/data/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/
COMMENT=	Software only MPEG-1/2 video decoder

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
