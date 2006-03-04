# $NetBSD: Makefile,v 1.19 2006/03/04 21:28:57 jlam Exp $

PKGNAME=	mpg123${TARGET_SUFFIX}-${MPG123_VERSION}
PKGREVISION=	9
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with NAS output

MAINTAINER=	pkgsrc-users@NetBSD.org

TARGET_SUFFIX=	-nas

CONFLICTS+=		mpg123-[0-9]*

NOT_FOR_COMPILER=	sunpro
ONLY_FOR_PLATFORM=	DragonFly-*-* FreeBSD-*-* Linux-*-* NetBSD-*-* \
			SunOS-*-*

PKG_OPTIONS_VAR=PKG_OPTIONS.mpg123-nas

.include "../../audio/mpg123/Makefile.common"

.include "../../audio/nas/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
