# $NetBSD: Makefile,v 1.1.1.1 2002/04/21 11:28:16 rh Exp $
#

DISTNAME=	rox-1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	RISC OS-like filer for X

DEPENDS+=	rox-base>=1.0.2:../../misc/rox-base

DIST_SUBDIR=	rox

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Filer/src

post-patch:
	${SED} -e "s:APPDIR:"${PREFIX}/apps":g" < ${FILESDIR}/rox > \
		${WRKDIR}/${DISTNAME}/rox

post-build:
	${CP} ${WRKSRC}/ROX-Filer ${WRKDIR}/${DISTNAME}/ROX-Filer

pre-install:
	${RM} -f ${WRKDIR}/${DISTNAME}/ROX-Filer/AppRun.orig
	${RM} -rf ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/apps
	${CP} -Rf ${WRKDIR}/${DISTNAME}/ROX-Filer ${PREFIX}/apps
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/rox ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/rox.1 ${PREFIX}/man/man1

.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
