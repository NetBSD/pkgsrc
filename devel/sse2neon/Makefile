# $NetBSD: Makefile,v 1.1 2026/01/05 16:58:17 adam Exp $

DISTNAME=	sse2neon-1.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=DLTcollab/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/DLTcollab/sse2neon
COMMENT=	Converts Intel SSE intrinsics to Arm/Aarch64 NEON intrinsics
LICENSE=	mit

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	include

do-install:
	${INSTALL_DATA} ${WRKSRC}/sse2neon.h ${DESTDIR}${PREFIX}/include/sse2neon.h

.include "../../mk/bsd.pkg.mk"
