# $NetBSD$

DISTNAME=	icecc-1.3.1
CATEGORIES= devel
MASTER_SITES=	https://github.com/icecc/icecream/releases/download/1.3.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	gang65@poczta.onet.pl
HOMEPAGE=	https://github.com/icecc/icecream/
COMMENT=	Tool for distributed C/C++ compiling with central scheduler
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	services/icecc.pc.in

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"

.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.  include "../../devel/libcap-ng/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
