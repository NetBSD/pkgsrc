# $NetBSD: Makefile,v 1.8 2004/04/24 23:16:32 wiz Exp $

PKGNAME=	mpg123${TARGET_SUFFIX}-${MPG123_VERSION}
PKGREVISION=	3
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with NAS output

TARGET_SUFFIX=	-nas

CONFLICTS+=	mpg123-[0-9]*

USE_X11=	yes

.include "../../audio/mpg123/Makefile.common"

.include "../../audio/nas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
