# $NetBSD: Makefile,v 1.20 2022/07/15 02:51:20 nat Exp $
#

VERSION=	1.1
GITHUB_PROJECT= unidiff
DISTNAME=       ${GITHUB_PROJECT}-${VERSION}
PKGNAME=        ${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GITHUB:=AceHusky12/}
EXTRACT_SUFX=	.zip

MAINTAINER=	nat@NetBSD.org
HOMEPAGE=	https://github.com/AceHusky12/unidiff
COMMENT=	Converts between uni-diffs and context diffs
LICENSE=	public-domain

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unify ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unipatch ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unify.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
