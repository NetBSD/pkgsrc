# $NetBSD: Makefile,v 1.4 2002/11/28 12:24:06 markd Exp $
#

PKGNAME=	mpg123${TARGET_SUFFIX}-${MPG123_VERSION}
PKGREVISION=	1
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with NAS output

TARGET_SUFFIX=	-nas

CONFLICTS+=	mpg123-[0-9]*

USE_X11BASE=	# defined

.include "../mpg123/Makefile.common"

.include "../../audio/nas/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
