# $NetBSD: Makefile,v 1.19 2004/12/16 06:56:55 minskim Exp $
#

DISTNAME=	ROX-Session-0.1.14
PKGNAME=	rox-session-0.1.14
PKGREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Very simple session manager

DEPENDS+=	rox>=1.2.0nb2:../../sysutils/rox

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Session/src
DIST_SUBDIR=	rox

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-build:
	${MV} ${WRKSRC} ${WRKDIR}/${DISTNAME}/src

pre-install:
	${RM} -f ${WRKDIR}/${DISTNAME}/ROX-Session/AppRun.orig
	${RM} -rf ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/src/ROX-Session	\
			${PREFIX}/libexec/rox
	${CP} -Rf ${WRKDIR}/${DISTNAME}/ROX-Session ${PREFIX}/share/rox
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" 				\
		< ${WRKDIR}/${DISTNAME}/ROX-Session/AppRun		\
			> ${PREFIX}/share/rox/ROX-Session/AppRun

.include "../../mk/bsd.pkg.mk"
