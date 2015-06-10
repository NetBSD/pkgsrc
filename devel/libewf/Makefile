# $NetBSD: Makefile,v 1.1 2015/06/10 20:15:24 pettai Exp $

DISTNAME=	libewf-experimental-20150126
PKGNAME=	libewf-20150126
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libyal/libewf/releases/download/20150126/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://github.com/libyal/libewf/wiki
COMMENT=	Library to access the Expert Witness Compression Format (EWF)
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libewf-20150126
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libewf.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../filesystems/fuse/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
