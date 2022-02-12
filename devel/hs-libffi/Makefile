# $NetBSD: Makefile,v 1.7 2022/02/12 08:50:34 pho Exp $

DISTNAME=	libffi-0.1
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell binding to libffi
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
