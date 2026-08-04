# $NetBSD: Makefile,v 1.33 2026/08/04 20:28:51 wiz Exp $

DISTNAME=	libhid-0.2.16
PKGREVISION=	20
CATEGORIES=	devel
MASTER_SITES=	http://sourceforge.net/projects/salix-sbo/files/13.37/libhid/
#MASTER_SITES+=	https://alioth.debian.org/frs/download.php/file/1958/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://libhid.alioth.debian.org/
COMMENT=	Abstraction layer for HID-class devices over USB/serial

TOOL_DEPENDS+=	docbook-[0-9]*:../../textproc/docbook

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PYTHON_LDFLAGS="-L${PREFIX}/lib -lpython${PYVERSSUFFIX}"

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.2.16

BUILDLINK_TRANSFORM+=	rm:-Werror

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../lang/python/extension.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
