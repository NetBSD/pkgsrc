# $NetBSD: Makefile,v 1.3 2024/06/13 13:46:59 bsiegert Exp $

DISTNAME=	humungus-0.9.7
PKGREVISION=	2
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
