# $NetBSD: Makefile,v 1.1 2021/05/26 18:44:44 brook Exp $

GITHUB_PROJECT=	miniasm
GITHUB_TAG=	refs/tags/v0.3
DISTNAME=	v0.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=lh3/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lh3/miniasm/
COMMENT=	OLC-based de novo assembler for long reads
LICENSE=	mit

WRKSRC=		${WRKDIR}/miniasm-0.3
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/miniasm

do-install:
	${INSTALL} ${WRKSRC}/miniasm ${DESTDIR}${PREFIX}/bin
	${INSTALL} ${WRKSRC}/minidot ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/miniasm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/PAF.md ${DESTDIR}${PREFIX}/share/doc/miniasm
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/miniasm

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
