# $NetBSD: Makefile,v 1.3 2011/10/17 19:45:56 shattered Exp $
#

MPG123_MODULE=	oss

PKGREVISION=	1
# this is builtin with ../mpg123 on all other architectures
ONLY_FOR_PLATFORM+=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-* SunOS-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

.include "${.CURDIR}/../../audio/mpg123/Makefile.common"

.include "../../mk/oss.buildlink3.mk"
LIBS+=		${LIBOSSAUDIO}
CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CPPFLAGS+=	-DDEVOSSSOUND="\"${DEVOSSSOUND}\""

.include "../../audio/mpg123/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
