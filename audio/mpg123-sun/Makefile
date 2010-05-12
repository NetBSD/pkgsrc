# $NetBSD: Makefile,v 1.2 2010/05/12 13:16:15 martin Exp $
#

MPG123_MODULE=	sun
# this is builtin with ../mpg123 on these architectures
NOT_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*
# there is no support for the sun-audio interface on theses
NOT_FOR_PLATFORM+=	DragonFly-*-* FreeBSD-*-*

.include "${.CURDIR}/../../audio/mpg123/Makefile.common"

.include "../../audio/mpg123/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
