# $NetBSD: Makefile,v 1.24 2025/09/02 11:59:00 pin Exp $

DISTNAME=	garden-2.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v2.3.0/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.81.0

WRKSRC=		${WRKDIR}/garden-v2.3.0-6935467df1d25794b1024e03309dd47dd6e7ce84

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
