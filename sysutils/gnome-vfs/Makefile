# $NetBSD: Makefile,v 1.12 2001/08/27 20:10:16 tron Exp $
#

DISTNAME=		gnome-vfs-1.0.1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-vfs/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System

BUILD_DEPENDS+=		autoconf>=2.50:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
BUILD_DEPENDS+=		xml-i18n-tools>=0.9:../../textproc/xml-i18n-tools
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
