# $NetBSD: Makefile,v 1.5 2023/05/20 13:59:11 pin Exp $

DISTNAME=	angle-grinder-0.19.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rcoh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rcoh/angle-grinder/
COMMENT=	Slice and dice logs on the command line
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS=	bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
