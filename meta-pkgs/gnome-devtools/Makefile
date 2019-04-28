# $NetBSD: Makefile,v 1.10 2019/04/28 07:07:48 wiz Exp $

DISTNAME=	gnome-devtools-2.26.1.99
PKGREVISION=	1
CATEGORIES=	meta-pkgs devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Meta-package for utilities used for developing GNOME applications

META_PACKAGE=	yes

# see http://ftp.gnome.org/pub/GNOME/devtools/2.26/2.26.2/sources/

DEPENDS+=	accerciser>=1.6.1:../../devel/accerciser
#DEPENDS+=	anjuta>=2.26.2.0:../../devel/anjuta
DEPENDS+=	anjuta>=2.24.2:../../devel/anjuta
DEPENDS+=	devhelp>=0.21:../../devel/devhelp
DEPENDS+=	gdl>=2.26.2:../../devel/gdl
DEPENDS+=	glade>=3.4.5:../../devel/glade
DEPENDS+=	gnome-devel-docs>=2.26.2:../../misc/gnome-devel-docs

.include "../../mk/bsd.pkg.mk"
