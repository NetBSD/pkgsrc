# $NetBSD: Makefile,v 1.11 2004/04/02 12:18:09 jmmv Exp $
#

DISTNAME=	System-0.1.2
PKGNAME=	rox-system-0.1.2
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Simple system monitor

DEPENDS+=	rox>=1.2.0nb2:../../sysutils/rox

WRKSRC=		${WRKDIR}/System/src
DIST_SUBDIR=	rox

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

APPDIR=		${PREFIX}/share/rox

post-patch:
	${CP} ${WRKDIR}/System/AppRun ${WRKDIR}
	${SED} -e "s:"\$$APP_DIR/\$$PLATFORM":${PREFIX}/libexec/rox:g" < \
		${WRKDIR}/AppRun > ${WRKDIR}/System/AppRun

post-build:
	${MV} ${WRKSRC} ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/src/System ${PREFIX}/libexec/rox
	${CP} -Rf ${WRKDIR}/System ${APPDIR}

.include "../../sysutils/libgtop/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
