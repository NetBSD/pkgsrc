# $NetBSD: Makefile,v 1.1.1.1 2003/03/25 01:32:55 salo Exp $
#

DISTNAME=	tuxracer-0.61
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxracer/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PKGBASE}-data-${PKGVERSION:C/nb[0-9]*$//}${EXTRACT_SUFX}

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://tuxracer.sourceforge.net/
COMMENT=	3D penguin racing game using OpenGL

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-data-dir=${PREFIX}/share/tuxracer

post-install:
	cd ${WRKSRC}/html && \
		${PAX} -rw . ${PREFIX}/share/doc/html/tuxracer/
	cd ${WRKSRC}/contrib && \
		${PAX} -rw . ${PREFIX}/share/examples/tuxracer/
	cd ${WRKDIR}/${PKGBASE}-data-${PKGVERSION:C/nb[0-9]*$//} && \
		${PAX} -rw . ${PREFIX}/share/tuxracer/
	cd ${PREFIX}/share/tuxracer && \
		${FIND} . -type f -exec ${CHMOD} 444 {} \;

.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
