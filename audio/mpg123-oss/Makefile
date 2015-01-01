# $NetBSD: Makefile,v 1.5 2015/01/01 09:11:09 dholland Exp $

MPG123_MODULE=	oss

# this is builtin with ../mpg123 on all other architectures
ONLY_FOR_PLATFORM+=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-* DragonFly-*-*
ONLY_FOR_PLATFORM+=	SunOS-*-*

.include "../../audio/mpg123/Makefile.common"

.include "../../mk/oss.buildlink3.mk"
LIBS+=		${LIBOSSAUDIO}
CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CPPFLAGS+=	-DDEVOSSSOUND="\"${DEVOSSSOUND}\""

.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
