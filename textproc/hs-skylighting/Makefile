# $NetBSD: Makefile,v 1.12 2023/02/07 01:41:13 pho Exp $

DISTNAME=	skylighting-0.13.2
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Syntax highlighting library
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	-fexecutable

# lib:skylighting
.include "../../textproc/hs-skylighting-core/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-ansi/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-blaze-html/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-context/buildlink3.mk"
.include "../../textproc/hs-skylighting-format-latex/buildlink3.mk"

# exe:skylighting
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../devel/hs-pretty-show/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
