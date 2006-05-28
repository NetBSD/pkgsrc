# $NetBSD: Makefile,v 1.10 2006/05/28 00:26:26 rh Exp $
#

DISTNAME=	cdplayer-0.4.2
PKGREVISION=	4
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	GNUstep CD player with CDDB support

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LANGUAGES=	objc
USE_TOOLS+=	gmake
MAKEFILE=	GNUmakefile
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="-Wno-import"

do-configure:
	${LN} -s ${BUILDLINK_DIR}/${GNUSTEP_SUBDIR}/System/Library/Frameworks/PrefsModule.framework/Versions/A/Headers ${WRKSRC}/AudioCD/AudioCDPrefs/PrefsModule

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/CDPlayer
	${INSTALL_DATA} ${WRKSRC}/CDPlayer/AudioCDProtocol.h		\
			${PREFIX}/include/CDPlayer

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../audio/cddb-bundle/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../x11/gnustep-preferences/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
