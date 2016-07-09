# $NetBSD: Makefile,v 1.3 2016/07/09 13:03:47 wiz Exp $

DISTNAME=	unicorn-0.9
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=unicorn-engine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unicorn-engine.org/
COMMENT=	CPU emulator engine framework based on QEMU
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # as of 0.9

.include "../../lang/python/application.mk"

MAKE_ENV+=	UNICORN_QEMU_FLAGS=--python=${PYTHONBIN:Q}

ALL_ENV+=	USE_GENERIC_LIBDATADIR=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
