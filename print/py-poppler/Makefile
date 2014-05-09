# $NetBSD: Makefile,v 1.7 2014/05/09 07:37:17 wiz Exp $

DISTNAME=	pypoppler-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	https://launchpad.net/poppler-python/trunk/development/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/poppler-python
COMMENT=	Python bindings for the Poppler PDF rendering library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PY_PATCHPLIST=	yes
PYTHON_VERSIONED_DEPENDENCIES=	cairo:link
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2

.include "../../lang/python/extension.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
BUILDLINK_API_DEPENDS.poppler-glib+=	poppler-glib>=0.12.1
.include "../../print/poppler-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=		${PYPKGPREFIX}-gtk2>=2.8.4
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
