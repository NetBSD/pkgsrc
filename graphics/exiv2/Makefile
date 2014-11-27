# $NetBSD: Makefile,v 1.37 2014/11/27 23:36:09 joerg Exp $

# Race condition between exiv2.cpp and creation of exv_conf.h
MAKE_JOBS_SAFE=	no

.include "Makefile.common"

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE=	config/exiv2.pc.in

LDFLAGS.Linux+=		-ldl

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
