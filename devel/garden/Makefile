# $NetBSD: Makefile,v 1.6 2024/01/16 21:27:13 pin Exp $

DISTNAME=	garden-1.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.1.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v1.1.0-0c530fa4942bf43c389df25a7306ec9fc59cb970

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
