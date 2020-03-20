# $NetBSD: Makefile,v 1.36 2020/03/20 11:57:45 nia Exp $
#

DISTNAME=	tuxracer-0.61
PKGREVISION=	16
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxracer/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PKGBASE}-data-${PKGVERSION:C/nb[0-9]*$//}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tuxracer.sourceforge.net/
COMMENT=	3D penguin racing game using OpenGL

GNU_CONFIGURE=	YES

CFLAGS+=		-DGLX_GLXEXT_PROTOTYPES
CONFIGURE_ARGS+=	--with-data-dir=${PREFIX}/share/tuxracer
CONFIGURE_ARGS+=	--with-tcl-libs=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:M*:Q}
USE_LANGUAGES=		c c++

USE_TOOLS+=	pax

INSTALLATION_DIRS=	share/doc/tuxracer share/examples/tuxracer \
			share/tuxracer

post-install:
	cd ${WRKSRC}/html && \
		pax -rw .  ${DESTDIR}${PREFIX}/share/doc/tuxracer/
	cd ${WRKSRC}/contrib && \
		pax -rw .  ${DESTDIR}${PREFIX}/share/examples/tuxracer/
	cd ${WRKDIR}/${PKGBASE}-data-${PKGVERSION:C/nb[0-9]*$//} && \
		pax -rw .  ${DESTDIR}${PREFIX}/share/tuxracer/
	cd ${DESTDIR}${PREFIX}/share/tuxracer && \
		${FIND} . -type f -exec ${CHMOD} 444 {} \;

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
