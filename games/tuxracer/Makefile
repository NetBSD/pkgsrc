# $NetBSD: Makefile,v 1.18 2005/05/02 23:02:06 reed Exp $
#

DISTNAME=	tuxracer-0.61
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxracer/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PKGBASE}-data-${PKGVERSION:C/nb[0-9]*$//}${EXTRACT_SUFX}

MAINTAINER=	david@silicium.ath.cx
HOMEPAGE=	http://tuxracer.sourceforge.net/
COMMENT=	3D penguin racing game using OpenGL

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

CFLAGS+=	-DGLX_GLXEXT_PROTOTYPES
CONFIGURE_ARGS+=	--with-data-dir=${PREFIX}/share/tuxracer
CONFIGURE_ARGS+=	--with-tcl-libs=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ENV+=		CFLAGS="${CFLAGS}"

post-install:
	@-${MKDIR} ${PREFIX}/share/doc/html/tuxracer ${PREFIX}/share/examples/tuxracer ${PREFIX}/share/tuxracer
	cd ${WRKSRC}/html && \
		${PAX} -rw . ${PREFIX}/share/doc/html/tuxracer/
	cd ${WRKSRC}/contrib && \
		${PAX} -rw . ${PREFIX}/share/examples/tuxracer/
	cd ${WRKDIR}/${PKGBASE}-data-${PKGVERSION:C/nb[0-9]*$//} && \
		${PAX} -rw . ${PREFIX}/share/tuxracer/
	cd ${PREFIX}/share/tuxracer && \
		${FIND} . -type f -exec ${CHMOD} 444 {} \;

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
