# $NetBSD: Makefile,v 1.29 2015/04/25 14:23:03 tnn Exp $
#

DISTNAME=	quake2-0.3
PKGNAME=	${DISTNAME:S/quake2/quake2forge/}
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.quakeforge.net/files/quake2forge/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.quakeforge.net/
COMMENT=	Enhanced Quake II engine
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=	rm:-Werror
CONFIGURE_ARGS+=	--program-transform-name='s/^quake2$$/quake2forge/'

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/quake2forge
	${INSTALL_DATA} ${WRKSRC}/docs/README* ${DESTDIR}${PREFIX}/share/doc/quake2forge
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${PREFIX}/share/doc/quake2forge

SUBST_CLASSES+=		snd data
SUBST_STAGE.snd=	post-patch
SUBST_FILES.snd=	src/snd_dma.c data/baseq2/config.cfg
SUBST_SED.snd=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.snd=	Fixing hardcoded audio device.
SUBST_STAGE.data=	post-patch
SUBST_FILES.data=	configure
SUBST_SED.data=		-e s,PACKAGE=\'quake2\',PACKAGE=\'${PKGBASE}\',g
SUBST_MESSAGE.data=	Fixing installation directories.

.include "../../mk/bsd.prefs.mk"

# Don't try to build the Sun Solaris sound module, it's broken.
.if !empty(OPSYS:MNetBSD) || !empty(OPSYS:MOpenBSD)
CONFIGURE_ENV+=		ac_cv_header_sys_audioio_h=no
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
