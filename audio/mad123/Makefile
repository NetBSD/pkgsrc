# $NetBSD: Makefile,v 1.4 2003/07/17 21:22:48 grant Exp $
#

DISTNAME=	mad123-0.7.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mctavish.co.uk/mad123/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mctavish.co.uk/mad123/
COMMENT=	Command-line MPEG audio player

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mad123 ${PREFIX}/bin/mad123

.include "../../mk/bsd.prefs.mk"

.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/id3lib/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
