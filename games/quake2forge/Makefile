# $NetBSD: Makefile,v 1.3 2004/04/17 10:36:05 xtraeme Exp $
#

DISTNAME=	quake2-0.2.1
PKGNAME=	${DISTNAME:S/quake2/quake2forge/}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quake/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.quakeforge.net/
COMMENT=	Quake2Forge is the Quake II engine

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=	S:-Werror:
CONFIGURE_ARGS+=	--program-transform-name='s/^quake2$$/quake2forge/'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quake2forge
	${INSTALL_DATA} ${WRKSRC}/docs/README* ${PREFIX}/share/doc/quake2forge
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/quake2forge

SUBST_CLASSES=	    snd
SUBST_STAGE.snd=    post-patch
SUBST_FILES.snd=    src/snd.c
SUBST_SED.snd=	    -e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.snd=  "Fixing harcoded audio device."

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
