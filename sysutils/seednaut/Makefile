# $NetBSD: Makefile,v 1.1 2026/05/21 00:17:58 gdt Exp $

DISTNAME=	seednaut-0.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Baltram/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/Baltram/seednaut/
COMMENT=	Extractor for seedvault encrypted backups (Android)
LICENSE=	apache-2.0 AND mit

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
