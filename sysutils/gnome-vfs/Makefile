# $NetBSD: Makefile,v 1.9 2001/05/14 17:11:36 rh Exp $
#

DISTNAME=		gnome-vfs-1.0.1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-vfs/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake-1.4:../../devel/automake
DEPENDS+=		GConf>=1.0.0:../../devel/GConf
BUILD_USES_MSGFMT=	YES

USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf && ${LOCALBASE}/bin/automake

.include "../../mk/bsd.pkg.mk"
