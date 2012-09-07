# $NetBSD: Makefile,v 1.56 2012/09/07 19:17:19 adam Exp $

DISTNAME=		ettercap-0.6.b
PKGREVISION=		14
CATEGORIES=		security net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ettercap/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN
LICENSE=		gnu-gpl-v2

CONFLICTS+=		ettercap-NG-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--enable-https

.include "options.mk"

# putwin() appeared in 4.99.60
INCOMPAT_CURSES=	NetBSD-[0-3]* NetBSD-4.[0-9].* NetBSD-4.99.[012345]*
USE_OLD_DES_API=	yes
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}

BUILD_DIRS=		. plugins
INSTALL_DIRS=		. plugins

.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
