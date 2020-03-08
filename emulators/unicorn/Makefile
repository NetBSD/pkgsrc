# $NetBSD: Makefile,v 1.13 2020/03/08 16:49:29 wiz Exp $

PKGREVISION= 3
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CPU emulator engine framework based on QEMU
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

PYTHON_VERSIONS_ACCEPTED=	27 # as of 1.0.1

.include "../../lang/python/application.mk"

MAKE_ENV+=	UNICORN_QEMU_FLAGS=--python=${PYTHONBIN:Q}
MAKE_ENV+=	UNICORN_QEMU_FLAGS=--extra-ldflags=\"${LDFLAGS:Q}\"

ALL_ENV+=	USE_GENERIC_LIBDATADIR=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
