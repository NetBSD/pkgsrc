# $NetBSD: Makefile,v 1.1.1.1 2002/06/04 17:47:58 cjep Exp $
#

DISTNAME=	System-0.1.2
PKGNAME=	rox-system-0.1.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	simple system monitor

DEPENDS+=	rox>=1.2.0nb2:../../sysutils/rox
DEPENDS+=	libgtop>=1.0.12nb2:../../devel/libgtop

DIST_SUBDIR=	rox

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/System/src

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

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
