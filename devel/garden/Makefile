# $NetBSD: Makefile,v 1.25 2026/01/01 20:17:01 pin Exp $

DISTNAME=	garden-2.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v2.5.0/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

WRKSRC=		${WRKDIR}/garden-v2.5.0-2b47cedc49ec1ff510dc27d3187fc5f69861488e

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
