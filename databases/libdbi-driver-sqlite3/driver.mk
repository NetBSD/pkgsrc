# $NetBSD: driver.mk,v 1.3 2020/01/26 05:26:20 rillig Exp $
#
# Common definitions for the individual DBI drivers (not only SQLite3).

DISTNAME=	libdbi-drivers-0.9.0
PKGNAME=	${DISTNAME:S/libdbi-drivers/libdbi-driver-${DRIVER}/:S/-1/.1/:S/-2/.2/}
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdbi-drivers/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://libdbi-drivers.sourceforge.net/

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

DISTINFO_FILE=		${.CURDIR}/../../databases/libdbi-driver-sqlite3/distinfo
PATCHDIR=		${.CURDIR}/../../databases/libdbi-driver-sqlite3/patches

INSTALLATION_DIRS+=	lib/dbd

CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--with-dbi-incdir=${BUILDLINK_PREFIX.libdbi}/include/dbi
CONFIGURE_ARGS+=	--with-dbi-libdir=${BUILDLINK_PREFIX.libdbi}/lib
CONFIGURE_ARGS+=	--disable-docs
