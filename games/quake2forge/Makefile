# $NetBSD: Makefile,v 1.10 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=	quake2-0.2.1
PKGNAME=	${DISTNAME:S/quake2/quake2forge/}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quake/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.quakeforge.net/
COMMENT=	Enhanced Quake II engine

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

USE_BUILTIN.glu=	yes
USE_BUILTIN.MesaLib=	yes

BUILDLINK_TRANSFORM+=	rm:-Werror
CONFIGURE_ARGS+=	--program-transform-name='s/^quake2$$/quake2forge/'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quake2forge
	${INSTALL_DATA} ${WRKSRC}/docs/README* ${PREFIX}/share/doc/quake2forge
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/quake2forge

SUBST_CLASSES=		snd data
SUBST_STAGE.snd=	post-patch
SUBST_FILES.snd=	src/snd.c
SUBST_SED.snd=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.snd=	"Fixing harcoded audio device."
SUBST_STAGE.data=	post-patch
SUBST_FILES.data=	configure
SUBST_SED.data=		-e "s|PACKAGE=quake2|PACKAGE=${PKGBASE}|g"
SUBST_MESSAGE.data=	"Fixing installation directories."

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
