# $NetBSD: Makefile,v 1.8 2004/04/01 19:17:24 jmmv Exp $

DISTNAME=	gnome-accessibility-2.6.0
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for accessibility applications of the GNOME desktop

DEPENDS+=	dasher>=3.2.8:../../editors/dasher
DEPENDS+=	gnome-base>=2.6.0:../../meta-pkgs/gnome-base
DEPENDS+=	gnome-mag>=0.10.10:../../x11/gnome-mag
DEPENDS+=	gnopernicus>=0.8.0:../../x11/gnopernicus

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
