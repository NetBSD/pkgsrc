# $NetBSD: Makefile,v 1.5.2.1 2004/02/10 15:59:42 agc Exp $

PKGNAME=	mpg123${TARGET_SUFFIX}-${MPG123_VERSION}
PKGREVISION=	3
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with NAS output

TARGET_SUFFIX=	-nas

CONFLICTS+=	mpg123-[0-9]*

USE_X11=	yes

.include "../../audio/mpg123/Makefile.common"

.include "../../audio/nas/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
