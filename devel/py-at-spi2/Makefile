# $NetBSD: Makefile,v 1.9 2013/05/18 23:05:34 prlw1 Exp $
#

DISTNAME=	pyatspi-2.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyatspi/at-spi2/}
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pyatspi/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Python Assistive Technology Service Provider Interface
# GPLv2 for pasytest, but tests are not built by default
LICENSE=	gnu-lgpl-v2

DEPENDS+=	at-spi2-core>=2.3.90:../../devel/at-spi2-core
DEPENDS+=	at-spi2-atk-[0-9]*:../../devel/at-spi2-atk

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_SELF_CONFLICT=		no

CONFLICTS=	${PYPKGPREFIX}-at-spi-[0-9]*

.include "../../devel/py-gobject3/buildlink3.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
