# $NetBSD: Makefile,v 1.3 2008/12/04 17:32:36 wiz Exp $

DISTNAME=	gnome-devtools-2.24.1.91
CATEGORIES=	meta-pkgs devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for utilities used for developing GNOME applications

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/devtools/2.24/2.24.2/sources/

# unpackaged
#DEPENDS+=	accerciser>=1.4.0:../../devel/accerciser
DEPENDS+=	anjuta>=2.24.2:../../devel/anjuta
DEPENDS+=	devhelp>=0.21:../../devel/devhelp
DEPENDS+=	gdl>=2.24.0:../../devel/gdl
DEPENDS+=	glade3>=3.4.5:../../devel/glade3
DEPENDS+=	gnome-build>=2.24.1:../../devel/gnome-build
# unpackaged
#DEPENDS+=	gnome-devel-docs>=2.24.0:../../devel/gnome-devel-docs

.include "../../mk/bsd.pkg.mk"
