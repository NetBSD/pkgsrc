# $NetBSD: Makefile,v 1.16 2006/01/09 21:42:49 tron Exp $

PKGNAME=	mpg123${TARGET_SUFFIX}-${MPG123_VERSION}
PKGREVISION=	8
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with NAS output

MAINTAINER=	tech-pkg@NetBSD.org

TARGET_SUFFIX=	-nas

CONFLICTS+=	mpg123-[0-9]*

PKG_OPTIONS_VAR=PKG_OPTIONS.mpg123-nas
.include "../../audio/mpg123/Makefile.common"

.include "../../audio/nas/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
