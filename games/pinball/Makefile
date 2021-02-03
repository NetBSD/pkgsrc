# $NetBSD: Makefile,v 1.1 2021/02/03 16:09:25 nia Exp $

DISTNAME=	pinball-0.3.20201218
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pinball/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pinball.sourceforge.net/
COMMENT=	Pinball simulator for Unix systems
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	aclocal autoconf automake autoreconf
USE_TOOLS+=	pkg-config

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-extract:
	# Otherwise automake complains.
	${TOUCH} -f ${WRKSRC}/README
	cd ${WRKSRC} && autoreconf -fi

post-install:
	${INSTALL_DATA} ${WRKSRC}/pinball.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/pinball.xpm \
	    ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
