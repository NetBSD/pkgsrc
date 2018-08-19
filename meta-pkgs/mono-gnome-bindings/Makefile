# $NetBSD: Makefile,v 1.10 2018/08/19 20:16:40 wiz Exp $

DISTNAME=	mono-gnome-bindings-2.26.2
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Meta-package for Mono (C\#) bindings for the GNOME desktop

META_PACKAGE=	yes

PREV_PKGPATH=	meta-pkgs/gnome-bindings-mono
SUPERSEDES=	gnome-bindings-mono-[0-9]*

# see http://ftp.gnome.org/pub/GNOME/bindings/2.26/2.26.2/sources/mono/

DEPENDS+=	gtk-sharp>=2.12.8:../../x11/gtk-sharp

.include "../../mk/bsd.pkg.mk"
