# $NetBSD: Makefile,v 1.9 2024/02/20 21:27:06 pin Exp $

DISTNAME=	garden-1.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.3.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v1.3.0-f1b59297a6918d32612e9103e49c629917cd75a9

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
