# $NetBSD: Makefile,v 1.17 2003/09/27 17:07:37 grant Exp $

DISTNAME=		ettercap-0.6.9
PKGREVISION=		3
CATEGORIES=		security net
MASTER_SITES=		http://ettercap.sourceforge.net/download/

MAINTAINER=		nk@bsdirc.net
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-plugins \
			--enable-https

USE_BUILDLINK2=		yes

USE_NCURSES=		# newpad(), MAX_FORM_COMMAND
PTHREAD_OPTS+=		require
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/plugins
INSTALL_DIRS=		${WRKSRC} ${WRKSRC}/plugins

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
