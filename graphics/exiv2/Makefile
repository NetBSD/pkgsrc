# $NetBSD: Makefile,v 1.40 2019/02/23 09:00:25 tnn Exp $

.include "Makefile.common"

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE=	config/exiv2.pc.in

LDFLAGS.Linux+=		-ldl
LIBS.SunOS+=	-lsocket -lnsl

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
