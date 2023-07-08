# $NetBSD: Makefile,v 1.3 2023/07/08 20:14:16 pin Exp $

DISTNAME=	iamb-0.0.8
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=ulyssa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://iamb.chat/
COMMENT=	Matrix client for Vim addicts
LICENSE=	apache-2.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
