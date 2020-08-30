# $NetBSD: Makefile,v 1.1 2020/08/30 10:41:01 jmcneill Exp $

GITHUB_PROJECT=	id3ren
GITHUB_TAG=	b061aba2bfa25bcde732776262cc2a19d66b416a
DISTNAME=	b061aba2bfa25bcde732776262cc2a19d66b416a
PKGNAME=	${GITHUB_PROJECT}-0.0.20130521
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=sebcode/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sebcode/id3ren/
COMMENT=	Rename batches of mp3 files using ID3 tags
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/id3ren-${GITHUB_TAG}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/id3ren \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/id3ren.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/id3ren.1

.include "../../mk/bsd.pkg.mk"
