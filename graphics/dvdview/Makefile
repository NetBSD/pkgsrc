# $NetBSD: Makefile,v 1.7 2003/05/02 11:55:13 wiz Exp $

DISTNAME=	dvdview-1.2.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/data/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/
COMMENT=	Software only MPEG-1/2 video decoder

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES
USE_BUILDLINK2=	yes

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
MAKE_ENV+=	RTLIB=-lrt
.else
MAKE_ENV+=	RTLIB=
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dvdview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dvdview

.include "../../graphics/libvideogfx/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
