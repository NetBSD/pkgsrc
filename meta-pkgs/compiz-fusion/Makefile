# $NetBSD: Makefile,v 1.5 2025/11/30 08:53:14 wiz Exp $

DISTNAME=	compiz-fusion-0.6
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.compiz-fusion.org/
COMMENT=	Meta-package for compiz fusion

META_PACKAGE=	yes

DEPENDS+=	compiz>=0.6.2:../../wm/compiz
DEPENDS+=	compiz-fusion-plugins-main>=0.6.0nb1:../../wm/compiz-fusion-plugins-main
DEPENDS+=	compiz-fusion-plugins-extra>=0.6.0:../../wm/compiz-fusion-plugins-extra
DEPENDS+=	ccsm>=0.6.0:../../wm/ccsm

.include "../../mk/bsd.pkg.mk"
