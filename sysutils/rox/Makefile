# $NetBSD: Makefile,v 1.6 2002/06/30 16:18:31 agc Exp $
#

DISTNAME=	rox-1.2.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	RISC OS-like filer for X

DEPENDS+=	rox-base>=1.0.2nb1:../../sysutils/rox-base

DIST_SUBDIR=	rox

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk2

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Filer/src

post-patch:
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" < ${FILESDIR}/rox > \
		${WRKDIR}/${DISTNAME}/rox

post-build:
	${MV} ${WRKSRC} ${WRKDIR}/${DISTNAME}/src

pre-install:
	${RM} -f ${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun.orig
	${RM} -rf ${WRKSRC}

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/rox
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/src/ROX-Filer	\
			${PREFIX}/libexec/rox
	${INSTALL_DATA_DIR} ${PREFIX}/share/rox/ROX-Filer
	cd ${WRKDIR}/${DISTNAME}/ROX-Filer && ${PAX} -rw . ${PREFIX}/share/rox/ROX-Filer
	${SED} -e "s:@PREFIX@:"${PREFIX}":g" <				\
		${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun > 		\
		${PREFIX}/share/rox/ROX-Filer/AppRun
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/rox ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/rox.1 ${PREFIX}/man/man1

.include "../../textproc/libxml2/buildlink.mk"
.include "../../x11/gtk2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
