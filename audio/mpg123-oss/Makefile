# $NetBSD: Makefile,v 1.1 2010/03/14 14:19:19 martin Exp $
#

MPG123_MODULE=	oss
# this is builtin with ../mpg123 on all other architectures
ONLY_FOR_PLATFORM+=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-* SunOS-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

.include "${.CURDIR}/../../audio/mpg123/Makefile.common"

LIBS+=		-lossaudio
CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CPPFLAGS+=	-DDEVOSSSOUND="\"${DEVOSSSOUND}\""

.include "../../mk/oss.buildlink3.mk"

.include "../../audio/mpg123/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
