# $NetBSD: Makefile,v 1.9 2019/04/26 13:13:56 maya Exp $

PKGREVISION= 1
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CPU emulator engine framework based on QEMU
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 1.0.1

.include "../../lang/python/application.mk"

MAKE_ENV+=	UNICORN_QEMU_FLAGS=--python=${PYTHONBIN:Q}

ALL_ENV+=	USE_GENERIC_LIBDATADIR=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
