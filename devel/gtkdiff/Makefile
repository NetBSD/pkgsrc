# $NetBSD: Makefile,v 1.21 2004/11/30 18:26:39 wiz Exp $
#

DISTNAME=	gtkdiff-1.8.0
PKGREVISION=	7
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.catv.ne.jp/pp/ginoue/software/gtkdiff/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://home.catv.ne.jp/pp/ginoue/software/gtkdiff/index-e.html
COMMENT=	Diff front-end program using GNOME

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
