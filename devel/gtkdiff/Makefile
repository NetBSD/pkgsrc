# $NetBSD: Makefile,v 1.14 2003/07/17 21:31:00 grant Exp $
#

DISTNAME=	gtkdiff-1.8.0
PKGREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.catv.ne.jp/pp/ginoue/software/gtkdiff/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://home.catv.ne.jp/pp/ginoue/software/gtkdiff/index-e.html
COMMENT=	diff front-end program using GNOME

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
