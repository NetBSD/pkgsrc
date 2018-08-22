# $NetBSD: Makefile,v 1.2 2018/08/22 09:46:35 wiz Exp $

DISTNAME=	libcap-2.25
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.kernel.org/pub/linux/libs/security/linux-privs/libcap2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/fullycapable/
COMMENT=	Library for getting and setting POSIX.1e capabilities
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config gmake perl

ONLY_FOR_PLATFORM=	Linux-*-*

PKGCONFIG_OVERRIDE+=	libcap/libcap.pc.in

MAKE_FLAGS+=	LIBDIR=${PREFIX}/lib
MAKE_FLAGS+=	SBINDIR=${PREFIX}/sbin
MAKE_FLAGS+=	INCDIR=${PREFIX}/include
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	PKGCONFIGDIR=${PREFIX}/lib/pkgconfig

INSTALL_MAKE_FLAGS+=	RAISE_SETFCAP=no
INSTALL_MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
