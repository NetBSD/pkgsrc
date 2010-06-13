# $NetBSD: Makefile,v 1.9 2010/06/13 22:45:03 wiz Exp $

DISTNAME=	dvdview-1.2.2
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/
COMMENT=	Software only MPEG-1/2 video decoder

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
MAKE_ENV+=	RTLIB=-lrt
.else
MAKE_ENV+=	RTLIB=
.endif

INSTALLATION_DIRS+=	share/doc/dvdview

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dvdview

.include "../../graphics/libvideogfx/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
