# $NetBSD: Makefile,v 1.13 2024/06/03 06:15:38 pin Exp $

DISTNAME=	garden-1.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.6.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v1.6.0-3de1690e94b0822f4d36c194de02bbb0f5216dd9

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
