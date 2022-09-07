# $NetBSD: Makefile,v 1.10 2022/09/07 06:50:52 pho Exp $

DISTNAME=	skylighting-0.12.2
PKGREVISION=	5
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
