# $NetBSD: Makefile,v 1.8 2004/09/22 11:16:35 scw Exp $
#

DISTNAME=	mad123-0.8.3
CATEGORIES=	audio
MASTER_SITES=	http://www.mctavish.co.uk/mad123/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mctavish.co.uk/mad123/
COMMENT=	Command-line MPEG audio player

USE_BUILDLINK3=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mad123 ${PREFIX}/bin/mad123
	${INSTALL_MAN} ${WRKSRC}/mad123.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.prefs.mk"

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
