# $NetBSD: Makefile,v 1.80 2025/10/27 12:20:05 pin Exp $

DISTNAME=	nushell-0.108.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=nushell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nushell.sh/
COMMENT=	New type of shell
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.88.0
USE_TOOLS+=	pkg-config

PKG_SHELL=	bin/nu

ARGMAX_REQ=	1048576

.include "../../lang/rust/cargo.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
