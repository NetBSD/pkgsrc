# $NetBSD: Makefile,v 1.25 2014/05/20 19:59:10 adam Exp $

MPG123_MODULE=	nas

NOT_FOR_COMPILER=	sunpro
ONLY_FOR_PLATFORM=	DragonFly-*-* FreeBSD-*-* Linux-*-* NetBSD-*-* \
			SunOS-*-*

.include "../../audio/mpg123/Makefile.common"

.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/nas/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
