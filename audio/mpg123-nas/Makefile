# $NetBSD: Makefile,v 1.10.2.1 2005/01/15 07:00:18 snj Exp $

PKGNAME=	mpg123${TARGET_SUFFIX}-${MPG123_VERSION}
PKGREVISION=	6
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with NAS output

TARGET_SUFFIX=	-nas

CONFLICTS+=	mpg123-[0-9]*

USE_X11=	yes

.include "../../audio/mpg123/Makefile.common"

.include "../../audio/nas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
