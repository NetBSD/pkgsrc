# $NetBSD: Makefile,v 1.15 2001/10/05 06:56:45 rh Exp $

DISTNAME=		gnome-vfs-1.0.2
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-vfs/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
BUILD_USES_MSGFMT=	YES

USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf && ${LOCALBASE}/bin/automake

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/GConf/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
