# $NetBSD: Makefile,v 1.15 2026/01/15 19:54:42 bsiegert Exp $

DISTNAME=	humungus-0.9.7
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	https://humungus.tedunangst.com/r/humungus/d/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://humungus.tedunangst.com/r/humungus
COMMENT=	Mercurial server
LICENSE=	0-clause-bsd

USE_TOOLS+=	pkg-config

.include "../../lang/go/go-module.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
