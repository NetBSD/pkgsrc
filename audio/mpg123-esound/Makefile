# $NetBSD: Makefile,v 1.21 2010/03/14 14:58:26 martin Exp $

MPG123_MODULE=	esd


.include "${.CURDIR}/../../audio/mpg123/Makefile.common"


USE_TOOLS+=	pkg-config

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
