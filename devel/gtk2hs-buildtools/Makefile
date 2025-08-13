# $NetBSD: Makefile,v 1.2 2025/08/13 11:06:27 pho Exp $

DISTNAME=	gtk2hs-buildtools-0.13.11.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools to build the Gtk2Hs suite of User Interface libraries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	alex happy

.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-hashtables/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
