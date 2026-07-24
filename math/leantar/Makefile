# $NetBSD: Makefile,v 1.1 2026/07/24 18:31:05 wiz Exp $

DISTNAME=	leangz-0.1.20
PKGNAME=	${DISTNAME:S/leangz/leantar/}
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=digama0/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/digama0/leangz/
COMMENT=	Lean 4 .olean file (de)compressor
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
