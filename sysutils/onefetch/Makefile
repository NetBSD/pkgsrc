# $NetBSD: Makefile,v 1.42 2026/03/26 19:38:33 pin Exp $

DISTNAME=	onefetch-2.27.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=o2sh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://onefetch.dev
COMMENT=	Git repository summary on your terminal
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config
RUST_REQ=		1.88.0

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
