# $NetBSD: Makefile,v 1.6 2015/04/07 05:13:45 sevan Exp $

MPG123_MODULE=	oss

# this is builtin with ../mpg123 on all other architectures
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* DragonFly-*-* SunOS-*-*

.include "../../audio/mpg123/Makefile.common"

.include "../../mk/oss.buildlink3.mk"
LIBS+=		${LIBOSSAUDIO}
CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CPPFLAGS+=	-DDEVOSSSOUND="\"${DEVOSSSOUND}\""

.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
