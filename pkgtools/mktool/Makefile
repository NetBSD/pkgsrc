# $NetBSD: Makefile,v 1.9 2024/09/12 10:57:45 jperkin Exp $

DISTNAME=	mktool-1.0.0
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=jperkin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jperkin@pkgsrc.org
HOMEPAGE=	https://github.com/jperkin/mktool/
COMMENT=	High performance alternatives for pkgsrc/mk
LICENSE=	isc

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
