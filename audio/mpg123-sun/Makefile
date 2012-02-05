# $NetBSD: Makefile,v 1.4 2012/02/05 21:20:17 sbd Exp $
#

MPG123_MODULE=	sun

PKGREVISION=	1
# this is builtin with ../mpg123 on these architectures
NOT_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*
# there is no support for the sun-audio interface on theses
NOT_FOR_PLATFORM+=	DragonFly-*-* FreeBSD-*-* Linux-*-*

.include "${.CURDIR}/../../audio/mpg123/Makefile.common"

.include "../../audio/mpg123/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
