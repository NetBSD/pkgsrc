# $NetBSD: Makefile,v 1.23 2025/01/14 20:47:31 wiz Exp $

DISTNAME=	mktool-1.4.2
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=jperkin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/jperkin/mktool/
COMMENT=	High performance alternatives for pkgsrc/mk
LICENSE=	isc

USE_LANGUAGES=	c

RUST_REQ=	1.74.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
