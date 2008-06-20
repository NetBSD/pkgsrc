# $NetBSD: Makefile,v 1.14 2008/06/20 01:09:21 joerg Exp $
#

DISTNAME=	gifsicle-1.41
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.lcdf.org/~eddietwo/gifsicle/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lcdf.org/~eddietwo/gifsicle/
COMMENT=	Create, edit, and inspect GIFs from shell

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
