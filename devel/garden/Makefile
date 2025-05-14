# $NetBSD: Makefile,v 1.23 2025/05/14 10:25:24 pin Exp $

DISTNAME=	garden-2.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v2.2.0/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.81.0

WRKSRC=		${WRKDIR}/garden-v2.2.0-bfdd61920e737916003b1549f7b666a236ae9efe

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
