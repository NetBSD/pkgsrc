# $NetBSD: Makefile,v 1.13 2026/08/30 08:30:36 he Exp $

DISTNAME=	dusage-0.4.0
CATEGORIES=	sysutils
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_GITHUB:=mihaigalos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mihaigalos/dusage/
COMMENT=	Command line disk usage information tool
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
