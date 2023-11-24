# $NetBSD: Makefile,v 1.1 2023/11/24 16:32:44 pin Exp $

DISTNAME=	scriptisto-2.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=igor-petruk/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/igor-petruk/scriptisto/
COMMENT=	Language-agnostic interpreter to write scripts in compiled languages
LICENSE=	apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES=	c c++

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
