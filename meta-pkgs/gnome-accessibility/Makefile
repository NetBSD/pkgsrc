# $NetBSD: Makefile,v 1.4 2004/02/22 20:48:15 jmmv Exp $

DISTNAME=	gnome-accessibility-2.4.2
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for accessibility applications of the GNOME desktop

DEPENDS+=	gnome-acme>=2.4.2:../../sysutils/gnome-acme
DEPENDS+=	gnome-base>=2.4.2:../../meta-pkgs/gnome-base
DEPENDS+=	gnome-mag>=0.10.4:../../x11/gnome-mag
DEPENDS+=	gnopernicus>=0.7.1:../../x11/gnopernicus

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
