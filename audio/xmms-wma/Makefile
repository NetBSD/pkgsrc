# $NetBSD: Makefile,v 1.1.1.1 2005/03/01 01:17:00 xtraeme Exp $
#

DISTNAME=	xmms-wma-1.0.4
CATEGORIES=	audio
MASTER_SITES=	http://mcmcc.bat.ru/xmms-wma/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mcmcc.bat.ru/xmms-wma/
COMMENT=	WMA input plugin for XMMS

ONLY_FOR_PLATFORM=  *-*-i386 # Doesn't seem to be very portable...

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux" # XXX
SUBST_CLASSES+=	    rintf
SUBST_STAGE.rintf=  pre-configure
SUBST_FILES.rintf=  ffmpeg-strip-wma/wmadec.c
SUBST_SED.rintf=    -e "s,lrintf,rintf,g"
.endif

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
