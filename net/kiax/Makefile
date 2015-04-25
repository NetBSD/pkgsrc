# $NetBSD: Makefile,v 1.28 2015/04/25 14:23:45 tnn Exp $

DISTNAME=	kiax-0.8.51-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	12
CATEGORIES=	comms net audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kiax/}

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://www.kiax.org/
COMMENT=	Open internet telephony system
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR:Q}

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qkiax.pro)
	(cd ${WRKSRC}/src && ${QTDIR}/bin/qmake -o Makefile src.pro)

LDFLAGS+=		${LIBOSSAUDIO}

# Fix hardcoded paths
SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	src/src.pro bin/Makefile
SUBST_SED.path=		-e 's:/usr/local:${PREFIX}:g'

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h) || \
    ${OPSYS} == "SunOS"
RT_LIB_SCHED=		-lrt
.else
RT_LIB_SCHED=		# empty
.endif
LDFLAGS+=		${RT_LIB_SCHED}

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
