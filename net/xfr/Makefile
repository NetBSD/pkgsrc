# $NetBSD: Makefile,v 1.10 2026/05/01 15:45:09 pin Exp $

DISTNAME=	xfr-0.9.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=lance0/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lance0/xfr/
COMMENT=	Modern network bandwidth testing with TUI
LICENSE=	apache-2.0 OR mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/examples/xfr

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/xfr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xfr.1
	${INSTALL_DATA} ${WRKSRC}/examples/config.toml \
		${DESTDIR}${PREFIX}/share/examples/xfr/config.toml

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
