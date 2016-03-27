# $NetBSD: Makefile,v 1.7 2016/03/27 22:46:45 jperkin Exp $

MPG123_MODULE=	sun

# this is builtin with ../mpg123 on these architectures
NOT_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*
# there is no support for the sun-audio interface on these
NOT_FOR_PLATFORM+=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-*

.include "../../audio/mpg123/Makefile.common"

.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
