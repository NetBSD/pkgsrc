# $NetBSD: Makefile,v 1.88 2026/05/27 10:09:33 pin Exp $

DISTNAME=	nushell-0.113.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=nushell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nushell.sh/
COMMENT=	New type of shell
LICENSE=	mit

RUST_REQ=	1.93.1
USE_TOOLS+=	pkg-config

PKG_SHELL=	bin/nu

ARGMAX_REQ=	1048576

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
