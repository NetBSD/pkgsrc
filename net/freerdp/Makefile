# $NetBSD: Makefile,v 1.34 2018/11/12 03:52:42 ryoon Exp $

DISTNAME=	freerdp-1.0.2
PKGREVISION=	32
CATEGORIES=	net
MASTER_SITES=	http://pub.freerdp.com/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freerdp.com/
COMMENT=	Free implementation of the Remote Desktop Protocol
LICENSE=	apache-2.0

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_OLD_DES_API=yes

PKGCONFIG_OVERRIDE+=	freerdp.pc.in

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
