# $NetBSD: Makefile,v 1.13 2007/02/01 17:10:38 joerg Exp $
#

DISTNAME=	gifsicle-1.41
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.lcdf.org/~eddietwo/gifsicle/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lcdf.org/~eddietwo/gifsicle/
COMMENT=	Create, edit, and inspect GIFs from shell

GNU_CONFIGURE=	YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
