# $NetBSD: Makefile,v 1.1 2020/01/17 17:32:25 pho Exp $

DISTNAME=	skylighting-0.8.3
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
