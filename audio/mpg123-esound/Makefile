# $NetBSD: Makefile,v 1.23 2012/01/13 10:54:47 obache Exp $

MPG123_MODULE=	esd

PKGREVISION=	2

.include "${.CURDIR}/../../audio/mpg123/Makefile.common"


USE_TOOLS+=	pkg-config

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
