# $NetBSD: Makefile,v 1.9 2003/12/08 14:41:40 wiz Exp $
#

DISTNAME=	tuxracer-0.61
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxracer/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PKGBASE}-data-${PKGVERSION:C/nb[0-9]*$//}${EXTRACT_SUFX}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://tuxracer.sourceforge.net/
COMMENT=	3D penguin racing game using OpenGL

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	-DGLX_GLXEXT_PROTOTYPES
CONFIGURE_ARGS+=	--with-data-dir=${PREFIX}/share/tuxracer
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

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
