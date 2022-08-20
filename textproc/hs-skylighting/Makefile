# $NetBSD: Makefile,v 1.8 2022/08/20 08:08:22 wiz Exp $

DISTNAME=	skylighting-0.12.2
PKGREVISION=	3
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
