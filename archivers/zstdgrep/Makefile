# $NetBSD: Makefile,v 1.1 2026/11/01 13:07:55 wiz Exp $

.include "../../archivers/zstd/Makefile.common"

PKGNAME=	${DISTNAME:S/zstd/zstdgrep/}
COMMENT=	Search in zstd-compressed files
LICENSE=	2-clause-bsd

DEPENDS+=	zstd>=1.5.7nb1:../../archivers/zstd

USE_TOOLS+=	ggrep

CONFLICTS+=	zstd<1.5.7nb1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/programs/zstdgrep ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/programs/zstdgrep.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
