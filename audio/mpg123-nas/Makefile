# $NetBSD: Makefile,v 1.5 2003/09/18 16:25:14 jmmv Exp $
#

PKGNAME=	mpg123${TARGET_SUFFIX}-${MPG123_VERSION}
PKGREVISION=	1
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with NAS output

TARGET_SUFFIX=	-nas

CONFLICTS+=	mpg123-[0-9]*

USE_X11BASE=	# defined

.include "../../audio/mpg123/Makefile.common"

.include "../../audio/nas/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
