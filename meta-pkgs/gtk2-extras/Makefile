# $NetBSD: Makefile,v 1.20 2007/12/19 12:27:28 rillig Exp $

DISTNAME=	gtk2-extras-2.8.0
PKGREVISION=	4
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtk.org/
COMMENT=	Meta-package for the GIMP Toolkit v2

DEPENDS+=	gtk2+>=2.8.4:../../x11/gtk2
DEPENDS+=	gtk2-engines>=2.6.0:../../x11/gtk2-engines
DEPENDS+=	librsvg>=2.12.6:../../graphics/librsvg
DEPENDS+=	swfdec-gtk2>=0.2.1nb1:../../multimedia/swfdec-gtk2

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
