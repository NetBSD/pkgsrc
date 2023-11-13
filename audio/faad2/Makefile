# $NetBSD: Makefile,v 1.60 2023/11/13 15:22:45 wiz Exp $

DISTNAME=	faad2-2.11.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=knik0/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/knik0/faad2
COMMENT=	AAC decoding library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++

CPPFLAGS.SunOS+=	-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE=1

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man3

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/libfaad.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_DATA} ${WRKSRC}/frontend/faad.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/faad.1

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
