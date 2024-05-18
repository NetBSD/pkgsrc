# $NetBSD: Makefile,v 1.7 2024/05/18 00:27:16 nia Exp $

VERSION=	2.28
DISTNAME=	minimap2-${VERSION}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=lh3/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lh3/minimap2
COMMENT=	Sequence alignment program for noisy, long reads
LICENSE=	mit

USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.simde

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL} ${WRKSRC}/minimap2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/minimap2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/simde/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
