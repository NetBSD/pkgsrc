# $NetBSD: Makefile,v 1.33 2024/05/08 08:04:48 pin Exp $

DISTNAME=	onefetch-2.21.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=o2sh/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/o2sh/onefetch/
COMMENT=	Git repository summary on your terminal
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/onefetch \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/onefetch.1  \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/onefetch.1

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
