# $NetBSD: Makefile,v 1.2 2008/05/12 13:23:50 jmcneill Exp $

DISTNAME=	compiz-fusion-0.6
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Meta-package for compiz fusion

DEPENDS+=	compiz>=0.6.2:../../wm/compiz
DEPENDS+=	compiz-fusion-plugins-main>=0.6.0nb1:../../wm/compiz-fusion-plugins-main
DEPENDS+=	compiz-fusion-plugins-extra>=0.6.0:../../wm/compiz-fusion-plugins-extra
DEPENDS+=	ccsm>=0.6.0:../../wm/ccsm
DEPENDS+=	gnome-session>=2.22.1.1nb2:../../x11/gnome-session

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
