# $NetBSD: Makefile,v 1.19 2022/06/30 11:18:22 nia Exp $

PKGREVISION= 2
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CPU emulator engine framework based on QEMU
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

.include "../../lang/python/application.mk"

MAKE_ENV+=	UNICORN_QEMU_FLAGS=--python=${PYTHONBIN:Q}
MAKE_ENV+=	UNICORN_QEMU_FLAGS=--extra-ldflags=\"${LDFLAGS:Q}\"
MAKE_ENV+=	CONFIG_SHELL=${CONFIG_SHELL:Q}

ALL_ENV+=	USE_GENERIC_LIBDATADIR=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
