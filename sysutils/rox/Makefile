# $NetBSD: Makefile,v 1.3 2002/05/26 19:45:44 cjep Exp $
#

DISTNAME=	rox-1.2.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	RISC OS-like filer for X

DEPENDS+=	rox-base>=1.0.2:../../sysutils/rox-base

DIST_SUBDIR=	rox

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk2

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Filer/src

post-patch:
	${SED} -e "s:APPDIR:"${PREFIX}/share/rox":g" < ${FILESDIR}/rox > \
		${WRKDIR}/${DISTNAME}/rox

post-build:
	${CP} ${WRKSRC}/ROX-Filer ${WRKDIR}/${DISTNAME}/ROX-Filer

pre-install:
	${RM} -f ${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun.orig
	${RM} -rf ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/rox
	${INSTALL} ${WRKDIR}/${DISTNAME}/ROX-Filer/ROX-Filer		\
			${PREFIX}/libexec/rox
	${RM} -f ${WRKDIR}/${DISTNAME}/ROX-Filer/ROX-Filer
	${CP} -Rf ${WRKDIR}/${DISTNAME}/ROX-Filer ${PREFIX}/share/rox
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" <				\
		${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun > 		\
		${PREFIX}/share/rox/ROX-Filer/AppRun
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/rox ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/rox.1 ${PREFIX}/man/man1

.include "../../textproc/libxml2/buildlink.mk"
.include "../../x11/gtk2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
