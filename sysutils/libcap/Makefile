# $NetBSD: Makefile,v 1.8 2022/07/25 11:12:28 wiz Exp $

DISTNAME=	libcap-2.44
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://www.kernel.org/pub/linux/libs/security/linux-privs/libcap2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/fullycapable/
COMMENT=	Library for getting and setting POSIX.1e capabilities
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake gsed perl

ONLY_FOR_PLATFORM=	Linux-*-*

PKGCONFIG_OVERRIDE+=	libcap/libcap.pc.in
PKGCONFIG_OVERRIDE+=	libcap/libpsx.pc.in

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	LIBDIR=${PREFIX}/lib
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	GOLANG=no

INSTALL_MAKE_FLAGS+=	RAISE_SETFCAP=no
INSTALL_MAKE_FLAGS+=	DESTDIR=${DESTDIR}

CHECK_PORTABILITY_SKIP+=	contrib/pcaps4server

.include "../../mk/bsd.pkg.mk"
