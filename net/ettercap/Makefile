# $NetBSD: Makefile,v 1.90 2020/04/24 11:56:56 nia Exp $

DISTNAME=		ettercap-0.6.b
PKGREVISION=		42
CATEGORIES=		security net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ettercap/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN
LICENSE=		gnu-gpl-v2

BROKEN=			"Fails to build with OpenSSL 1.1"

CONFLICTS+=		ettercap-NG-[0-9]*

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-plugins
CONFIGURE_ARGS+=	--enable-https

.include "options.mk"

# needs putwin()
INCOMPAT_CURSES=	NetBSD-[0-4].*
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}

BUILD_DIRS=		. plugins
INSTALL_DIRS=		. plugins

.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
