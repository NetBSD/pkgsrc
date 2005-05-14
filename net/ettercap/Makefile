# $NetBSD: Makefile,v 1.37 2005/05/14 16:46:17 adrianp Exp $

DISTNAME=		ettercap-0.6.b
PKGREVISION=		2
CATEGORIES=		security net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ettercap/} \
			http://ettercap.sourceforge.net/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN

CONFLICTS+=		ettercap-NG-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-plugins \
			--enable-https \
			--disable-gtk


USE_NCURSES=		# putwin()
USE_OLD_DES_API=	yes
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/plugins
INSTALL_DIRS=		${WRKSRC} ${WRKSRC}/plugins

.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
