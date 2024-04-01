# $NetBSD: Makefile,v 1.1 2024/04/01 21:41:35 wiz Exp $

DISTNAME=	sha3sum-v1.2.0
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITLAB:=kurdy/sha3sum/-/archive/v${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/kurdy/sha3sum
COMMENT=	Compute and check sha3xxx message digest
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
