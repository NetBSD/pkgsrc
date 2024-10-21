# $NetBSD: Makefile,v 1.21 2024/10/21 14:20:11 jperkin Exp $

DISTNAME=	mktool-1.4.1
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=jperkin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jperkin@pkgsrc.org
HOMEPAGE=	https://github.com/jperkin/mktool/
COMMENT=	High performance alternatives for pkgsrc/mk
LICENSE=	isc

USE_LANGUAGES=	c

RUST_REQ=	1.74.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
