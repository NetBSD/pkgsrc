# $NetBSD: Makefile,v 1.7 2009/05/21 11:38:50 wiz Exp $

DISTNAME=	gnome-devtools-2.26.1.99
CATEGORIES=	meta-pkgs devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Meta-package for utilities used for developing GNOME applications

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/devtools/2.26/2.26.2/sources/

DEPENDS+=	accerciser>=1.6.1:../../devel/accerciser
#DEPENDS+=	anjuta>=2.26.2.0:../../devel/anjuta
DEPENDS+=	anjuta>=2.24.2:../../devel/anjuta
DEPENDS+=	devhelp>=0.21:../../devel/devhelp
DEPENDS+=	gdl>=2.26.2:../../devel/gdl
#DEPENDS+=	glade3>=3.6.3:../../devel/glade3
DEPENDS+=	glade3>=3.4.5:../../devel/glade3
DEPENDS+=	gnome-devel-docs>=2.26.2:../../misc/gnome-devel-docs

.include "../../mk/bsd.pkg.mk"
