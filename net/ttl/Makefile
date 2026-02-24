# $NetBSD: Makefile,v 1.1 2026/02/24 11:59:09 pin Exp $

DISTNAME=	ttl-0.18.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=lance0/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lance0/ttl/
COMMENT=	Modern traceroute with real-time TUI
LICENSE=	apache-2.0 OR mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

.include "../../lang/rust/cargo.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
