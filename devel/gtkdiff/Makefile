# $NetBSD: Makefile,v 1.17 2004/01/03 18:49:38 reed Exp $
#

DISTNAME=	gtkdiff-1.8.0
PKGREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.catv.ne.jp/pp/ginoue/software/gtkdiff/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://home.catv.ne.jp/pp/ginoue/software/gtkdiff/index-e.html
COMMENT=	Diff front-end program using GNOME

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
