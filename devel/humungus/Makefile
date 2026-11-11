# $NetBSD: Makefile,v 1.25.2.2 2026/11/11 20:31:59 maya Exp $

DISTNAME=	humungus-0.9.7
PKGREVISION=	26
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
