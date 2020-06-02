# $NetBSD: Makefile,v 1.41 2020/06/02 08:23:08 adam Exp $
#

DISTNAME=	cdplayer-0.5.1
PKGREVISION=	18
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	GNUstep CD player with CDDB support
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/CDPlayer-${PKGVERSION_NOREV}
USE_LANGUAGES=	objc
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
MAKE_FILE=	GNUmakefile
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="-Wno-import"
MAKE_ENV+=	GNUSTEP_LIB_DIR=${GNUSTEP_LIB_DIR:Q}

INSTALLATION_DIRS+=	include/CDPlayer

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../x11/gnustep-preferences/buildlink3.mk"
.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../audio/cddb-bundle/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
