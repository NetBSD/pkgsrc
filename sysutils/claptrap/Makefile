# $NetBSD: Makefile,v 1.1 2026/08/11 18:16:52 pin Exp $

DISTNAME=	claptrap-0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=fujiapple852/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://claptrap.sh/
COMMENT=	Bring the power of Clap to shell scripts
LICENSE=	apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.82.0

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
