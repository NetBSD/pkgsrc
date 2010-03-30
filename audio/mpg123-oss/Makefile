# $NetBSD: Makefile,v 1.2 2010/03/30 10:29:22 martin Exp $
#

MPG123_MODULE=	oss
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
