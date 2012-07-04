# $NetBSD: Makefile,v 1.1 2012/07/04 18:41:20 prlw1 Exp $
#

DISTNAME=	pyatspi-2.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyatspi/at-spi2/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pyatspi/2.5/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/accessibility/atk/at-spi/at-spi_on_d-bus
COMMENT=	Python Assistive Technology Service Provider Interface
# GPLv2 for pasytest, but tests are not built by default
LICENSE=	gnu-lgpl-v2

DEPENDS+=	at-spi2-core>=2.3.90:../../devel/at-spi2-core
DEPENDS+=	at-spi2-atk-[0-9]*:../../devel/at-spi2-atk

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes

CONFLICTS=	${PYPKGPREFIX}-at-spi-[0-9]*

.include "../../devel/py-gobject3/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
