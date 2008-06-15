# $NetBSD: Makefile,v 1.3 2008/06/15 09:51:59 joerg Exp $

DISTNAME=	compiz-fusion-0.6
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Meta-package for compiz fusion

META_PACKAGE=	yes

DEPENDS+=	compiz>=0.6.2:../../wm/compiz
DEPENDS+=	compiz-fusion-plugins-main>=0.6.0nb1:../../wm/compiz-fusion-plugins-main
DEPENDS+=	compiz-fusion-plugins-extra>=0.6.0:../../wm/compiz-fusion-plugins-extra
DEPENDS+=	ccsm>=0.6.0:../../wm/ccsm
DEPENDS+=	gnome-session>=2.22.1.1nb2:../../x11/gnome-session

.include "../../mk/bsd.pkg.mk"
