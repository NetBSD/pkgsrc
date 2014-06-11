# $NetBSD: Makefile,v 1.36 2014/06/11 10:58:40 jperkin Exp $

.include "Makefile.common"

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE=	config/exiv2.pc.in

LDFLAGS.Linux+=		-ldl

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
