# $NetBSD: Makefile,v 1.4 2003/05/02 11:56:28 wiz Exp $
#

DISTNAME=	System-0.1.2
PKGREVISION=	1
PKGNAME=	rox-system-0.1.2
WRKSRC=		${WRKDIR}/System/src
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	simple system monitor

DEPENDS+=	rox>=1.2.0nb2:../../sysutils/rox

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

.include "../../devel/libgtop/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
