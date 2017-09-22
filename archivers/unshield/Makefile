# $NetBSD: Makefile,v 1.8 2017/09/22 23:26:20 wiedi Exp $

DISTNAME=       unshield-1.4.2
PKGREVISION=	1
MASTER_SITES=   ${MASTER_SITE_GITHUB:=twogood/}
GITHUB_TAG=     ${PKGVERSION_NOREV}
EXTRACT_SUFX=   .zip

CATEGORIES=	archivers
COMMENT=	Extract InstallShield .CAB files
LICENSE=	mit

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes
USE_LANGUAGES+=		c++ c

LDFLAGS+=	-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
