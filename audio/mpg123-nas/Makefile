# $NetBSD: Makefile,v 1.24 2011/10/17 19:45:56 shattered Exp $

MPG123_MODULE=	nas

PKGREVISION=	1

NOT_FOR_COMPILER=	sunpro
ONLY_FOR_PLATFORM=	DragonFly-*-* FreeBSD-*-* Linux-*-* NetBSD-*-* \
			SunOS-*-*

.include "${.CURDIR}/../../audio/mpg123/Makefile.common"

.include "../../audio/nas/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
