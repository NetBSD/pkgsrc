# $NetBSD: Makefile,v 1.2 2008/11/29 08:34:29 wiz Exp $

DISTNAME=	mono-gnome-bindings-2.24.2
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for Mono (C#) bindings for the GNOME desktop

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/bindings/2.24/2.24.2/sources/mono/

DEPENDS+=	gtk-sharp>=2.12.6:../../x11/gtk-sharp

.include "../../mk/bsd.pkg.mk"
