# $NetBSD: Makefile,v 1.4 2019/09/16 10:50:47 nia Exp $

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

.include "../../mk/bsd.pkg.mk"
