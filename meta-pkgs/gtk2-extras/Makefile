# $NetBSD: Makefile,v 1.19 2007/10/25 22:00:52 jlam Exp $

DISTNAME=	gtk2-extras-2.8.0
PKGREVISION=	4
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtk.org/
COMMENT=	Meta-package for the GIMP Toolkit v2

DEPENDS+=	gtk2+>=2.8.4:../../x11/gtk2
DEPENDS+=	gtk2-engines>=2.6.0:../../x11/gtk2-engines
DEPENDS+=	librsvg>=2.12.6:../../graphics/librsvg
DEPENDS+=	swfdec-gtk2>=0.2.1nb1:../../multimedia/swfdec-gtk2

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
