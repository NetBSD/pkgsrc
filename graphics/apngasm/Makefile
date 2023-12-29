# $NetBSD: Makefile,v 1.2 2023/12/29 18:24:46 adam Exp $

DISTNAME=		apngasm-3.1.10
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=apngasm/}
GITHUB_PROJECT=		${DISTNAME:S/-${PKGVERSION_NOREV}//}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://github.com/apngasm/apngasm
COMMENT=		CLI tool to assemble and disassemble APNG images
LICENSE=		zlib

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	filesystem
MAKE_JOBS_SAFE=		no	# XXX lib and cli are built in parallel?

INSTALLATION_DIRS+=	bin include lib ${PKGMANDIR}/man1

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
