# $NetBSD: Makefile,v 1.14 2020/06/02 08:23:38 adam Exp $

DISTNAME=	libhid-0.2.16
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/salix-sbo/files/13.37/libhid/
MASTER_SITES+=	https://alioth.debian.org/frs/download.php/file/1958/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libhid.alioth.debian.org/
COMMENT=	Abstraction layer for HID-class devices over USB/serial

BUILD_DEPENDS+=	docbook-[0-9]*:../../textproc/docbook

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PYTHON_LDFLAGS="-L${PREFIX}/lib -lpython${PYVERSSUFFIX}"

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.2.16

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../lang/python/extension.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
