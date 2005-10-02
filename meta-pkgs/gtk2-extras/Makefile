# $NetBSD: Makefile,v 1.12 2005/10/02 12:19:53 jmmv Exp $

DISTNAME=	gtk2-extras-2.8.0
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gtk.org/
COMMENT=	Meta-package for the GIMP Toolkit v2

DEPENDS+=	gtk2+>=2.8.4:../../x11/gtk2
DEPENDS+=	gtk2-engines>=2.6.0:../../x11/gtk2-engines
DEPENDS+=	librsvg2-gtk2>=2.6.3:../../graphics/librsvg2-gtk2
DEPENDS+=	swfdec-gtk2>=0.2.1nb1:../../multimedia/swfdec-gtk2

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
