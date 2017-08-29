# $NetBSD: Makefile,v 1.7 2017/08/29 11:18:40 martin Exp $

DISTNAME=       unshield-1.4.2
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

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
