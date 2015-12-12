# $NetBSD: Makefile,v 1.1 2015/12/12 01:26:39 kamil Exp $

DISTNAME=	unicorn-0.9
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=unicorn-engine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unicorn-engine.org/
COMMENT=	CPU emulator engine framework based on QEMU
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

.include "../../lang/python/application.mk"

MAKE_ENV+=	UNICORN_QEMU_FLAGS=--python=${PYTHONBIN:Q}

ALL_ENV+=	USE_GENERIC_LIBDATADIR=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
