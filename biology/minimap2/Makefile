# $NetBSD: Makefile,v 1.2 2021/05/29 17:35:18 brook Exp $

GITHUB_PROJECT=	minimap2
GITHUB_TAG=	refs/tags/v2.18
DISTNAME=	v2.18
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=lh3/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lh3/minimap2
COMMENT=	Sequence alignment program for noisy, long reads
LICENSE=	mit

WRKSRC=		${WRKDIR}/minimap2-2.18
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL} ${WRKSRC}/minimap2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/minimap2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
