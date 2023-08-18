# $NetBSD: Makefile,v 1.3 2023/08/18 20:31:23 pin Exp $

DISTNAME=	lla-0.1.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=triyanox/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/triyanox/lla/
COMMENT=	The Elegant ls Alternative
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
