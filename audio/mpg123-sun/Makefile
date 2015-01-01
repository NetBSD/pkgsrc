# $NetBSD: Makefile,v 1.6 2015/01/01 07:56:42 dholland Exp $

MPG123_MODULE=	sun

# this is builtin with ../mpg123 on these architectures
NOT_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*
# there is no support for the sun-audio interface on these
NOT_FOR_PLATFORM+=	DragonFly-*-* FreeBSD-*-* Linux-*-*

.include "../../audio/mpg123/Makefile.common"

.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
