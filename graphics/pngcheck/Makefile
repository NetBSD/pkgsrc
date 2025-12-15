# $NetBSD: Makefile,v 1.6 2025/12/15 21:06:00 wiz Exp $

DISTNAME=	pngcheck-4.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=pnggroup/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pnggroup/pngcheck
COMMENT=	Verify the integrity of PNG, JNG, and MNG files

INSTALLATION_DIRS=	bin share/doc/pngcheck ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} ${LIBS} -DUSE_ZLIB \
		-o pngcheck pngcheck.c -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pngcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pngcheck.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/pngcheck

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
