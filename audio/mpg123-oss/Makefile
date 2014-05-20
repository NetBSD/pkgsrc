# $NetBSD: Makefile,v 1.4 2014/05/20 19:59:10 adam Exp $

MPG123_MODULE=	oss

# this is builtin with ../mpg123 on all other architectures
ONLY_FOR_PLATFORM+=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-* SunOS-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

.include "../../audio/mpg123/Makefile.common"

.include "../../mk/oss.buildlink3.mk"
LIBS+=		${LIBOSSAUDIO}
CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CPPFLAGS+=	-DDEVOSSSOUND="\"${DEVOSSSOUND}\""

.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
