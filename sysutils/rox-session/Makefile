# $NetBSD: Makefile,v 1.1.1.1 2002/05/26 20:22:07 cjep Exp $
#

DISTNAME=	ROX-Session-0.1.14
PKGNAME=	rox-session-0.1.14
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	very simple session manager

DEPENDS+=	rox>=1.2.0nb1:../../sysutils/rox

DIST_SUBDIR=	rox

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Session/src

post-build:
	${CP} ${WRKSRC}/ROX-Session ${WRKDIR}/${DISTNAME}/ROX-Session

pre-install:
	${RM} -f ${WRKDIR}/${DISTNAME}/ROX-Session/AppRun.orig
	${RM} -rf ${WRKSRC}

do-install:
	${INSTALL} ${WRKDIR}/${DISTNAME}/ROX-Session/ROX-Session	\
			${PREFIX}/libexec/rox
	${RM} -f ${WRKDIR}/${DISTNAME}/ROX-Session/ROX-Session
	${CP} -Rf ${WRKDIR}/${DISTNAME}/ROX-Session ${PREFIX}/share/rox
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" 				\
		< ${WRKDIR}/${DISTNAME}/ROX-Session/AppRun		\
			> ${PREFIX}/share/rox/ROX-Session/AppRun

.include "../../textproc/libxml2/buildlink.mk"
.include "../../x11/gtk2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
