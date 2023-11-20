# $NetBSD: Makefile,v 1.4 2023/11/20 07:44:35 pin Exp $

DISTNAME=	garden-0.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v0.9.1/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v0.9.1-5439935d4803c8c8703b0e2c16c7e91cb6a877d2

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
