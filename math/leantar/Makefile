# $NetBSD: Makefile,v 1.2 2026/07/26 18:27:32 wiz Exp $

DISTNAME=	leangz-0.1.20
PKGNAME=	${DISTNAME:S/leangz/leantar/}
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=digama0/}
GITHUB_PROJECT=	leangz
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
