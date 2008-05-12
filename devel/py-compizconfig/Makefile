# $NetBSD: Makefile,v 1.1.1.1 2008/05/12 11:20:58 jmcneill Exp $
#

DISTNAME=		compizconfig-python-0.6.0
PKGNAME=		${PYPKGPREFIX}-compizconfig-0.6.0
CATEGORIES=		devel gnome
MASTER_SITES=		http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.compiz-fusion.org/
COMMENT=		Python bindings for libcompizconfig

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake

PY_PATCHPLIST=		yes

BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

.include "../../wm/compiz/buildlink3.mk"
.include "../../devel/libcompizconfig/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
