# $NetBSD: Makefile,v 1.26 2006/01/24 07:32:35 wiz Exp $
#

DISTNAME=	ROX-Session-0.1.14
PKGNAME=	rox-session-0.1.14
PKGREVISION=	12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Very simple session manager

DEPENDS+=	rox>=1.2.0nb2:../../sysutils/rox

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Session/src
DIST_SUBDIR=	rox

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	libexec/rox share/rox

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
