# $NetBSD: Makefile,v 1.22 2011/10/17 19:45:55 shattered Exp $

MPG123_MODULE=	esd

PKGREVISION=	1

.include "${.CURDIR}/../../audio/mpg123/Makefile.common"


USE_TOOLS+=	pkg-config

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
