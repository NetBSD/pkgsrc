# $NetBSD: Makefile,v 1.1 2022/03/02 22:55:15 pin Exp $

DISTNAME=	davis-0.1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=SimonPersson/}
GITHUB_PROJECT=	davis
GITHUB_TAG=	f16a22288e6cac4b62ba8cc25cba06c6ae4a89ab

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SimonPersson/davis/
COMMENT=	CLI client for MPD
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/davis \
		 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/davis.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/davis.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
