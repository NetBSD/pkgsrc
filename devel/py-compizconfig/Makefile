# $NetBSD: Makefile,v 1.100 2024/05/29 16:32:18 adam Exp $

PKGVER=			0.8.4
DISTNAME=		compizconfig-python-${PKGVER}
PKGNAME=		${PYPKGPREFIX}-compizconfig-${PKGVER}
PKGREVISION=		80
CATEGORIES=		devel gnome
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://compiz.org/
COMMENT=		Python bindings for libcompizconfig
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0.9.3:../../lang/py-pyrex

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_ACCEPTED=	 27 # py-pyrex

.include "../../wm/compiz/buildlink3.mk"
.include "../../devel/libcompizconfig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
