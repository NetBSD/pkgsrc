# $NetBSD: Makefile,v 1.4 2022/01/18 02:48:28 pho Exp $

DISTNAME=	skylighting-0.10.5.1
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Syntax highlighting library
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	-fexecutable

.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk" # Only for executable
.include "../../devel/hs-pretty-show/buildlink3.mk"   # Only for executable
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
