# $NetBSD: Makefile,v 1.39 2018/12/09 03:04:34 sevan Exp $

# Race condition between exiv2.cpp and creation of exv_conf.h
MAKE_JOBS_SAFE=	no

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
