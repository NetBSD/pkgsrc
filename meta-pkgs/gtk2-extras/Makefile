# $NetBSD: Makefile,v 1.1.1.1 2004/01/24 22:51:51 jmmv Exp $

DISTNAME=	gtk2-extras-2.2.4
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gtk.org/
COMMENT=	Meta-package for the GIMP Toolkit v2

DEPENDS+=	gtk2+>=2.2.4:../../x11/gtk2
DEPENDS+=	gtk2-engines>=2.2.0:../../x11/gtk2-engines
DEPENDS+=	librsvg2-gtk2>=2.5.0:../../graphics/librsvg2-gtk2
DEPENDS+=	swfdec-gtk2>=0.2.1:../../graphics/swfdec-gtk2

USE_X11=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
