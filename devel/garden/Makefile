# $NetBSD: Makefile,v 1.12 2024/04/15 07:42:54 pin Exp $

DISTNAME=	garden-1.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.5.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v1.5.0-bd52d7f83a468b5dd7a539c62eba8903967f0d22

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
