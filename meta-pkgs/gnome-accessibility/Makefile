# $NetBSD: Makefile,v 1.9 2004/05/15 18:53:21 jmmv Exp $

DISTNAME=	gnome-accessibility-2.6.1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for accessibility applications of the GNOME desktop

DEPENDS+=	dasher>=3.2.10:../../editors/dasher
DEPENDS+=	gnome-base>=2.6.1:../../meta-pkgs/gnome-base
DEPENDS+=	gnome-mag>=0.10.11:../../x11/gnome-mag
DEPENDS+=	gnopernicus>=0.8.1:../../x11/gnopernicus

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
