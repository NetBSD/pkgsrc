# $NetBSD: Makefile,v 1.3 2006/01/30 22:36:01 wiz Exp $
#

DISTNAME=		kiax-0.8.4
CATEGORIES=		comms net audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kiax/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reinoud@NetBSD.org
HOMEPAGE=		http://www.kiax.org/
COMMENT=		Open internet telephony system

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
HAS_CONFIGURE=		yes

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qkiax.pro)
	(cd ${WRKSRC}/src && ${QTDIR}/bin/qmake -o Makefile src.pro)

LIBS+=			${LIBOSSAUDIO}

# Fix hardcoded paths
SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	src/src.pro bin/Makefile
SUBST_SED.path=		-e 's:/usr/local:${PREFIX}:g'

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
