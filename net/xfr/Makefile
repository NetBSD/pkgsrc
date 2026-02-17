# $NetBSD: Makefile,v 1.3 2026/02/17 14:00:16 pin Exp $

DISTNAME=	xfr-0.8.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=lance0/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lance0/xfr/
COMMENT=	Modern network bandwidth testing with TUI
LICENSE=	apache-2.0 OR mit

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
