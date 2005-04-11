# $NetBSD: Makefile,v 1.46 2005/04/11 21:46:29 tv Exp $

DISTNAME=	Guppi-0.40.3
PKGNAME=	${DISTNAME:S/G/g/}
PKGREVISION=	13
CATEGORIES=	math graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/Guppi/0.40/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/guppi/
COMMENT=	Plot program with integrated statistics capabilities

# guppi is no longer maintained, see e.g.
# http://mail.gnome.org/archives/guppi-list/2004-June/msg00001.html
# only left here for gnucash

# works only with gnumeric-1.0.x (gnome1 based)
CONFIGURE_ARGS=		--disable-gnumeric

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
