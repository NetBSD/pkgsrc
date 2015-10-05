# $NetBSD: Makefile,v 1.38 2015/10/05 08:42:25 richard Exp $

# Race condition between exiv2.cpp and creation of exv_conf.h
MAKE_JOBS_SAFE=	no

.include "Makefile.common"

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE=	config/exiv2.pc.in

LDFLAGS.Linux+=		-ldl
LIBS.SunOS+=	-lsocket -lnsl

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
