# $NetBSD: Makefile,v 1.20 2023/05/10 19:14:50 adam Exp $

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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/lib/libunicorn.1.dylib \
	${DESTDIR}${PREFIX}/lib/libunicorn.1.dylib
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
