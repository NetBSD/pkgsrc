# $NetBSD: Makefile,v 1.31 2004/10/22 14:10:44 ben Exp $

DISTNAME=		ettercap-0.6.b
PKGREVISION=		2
CATEGORIES=		security net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ettercap/} \
			http://ettercap.sourceforge.net/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-plugins \
			--enable-https \
			--disable-gtk

USE_BUILDLINK3=		yes

USE_NCURSES=		# putwin()
PTHREAD_OPTS+=		require
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}
LIBS+=			-ldes ${PTHREAD_LDFLAGS}

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/plugins
INSTALL_DIRS=		${WRKSRC} ${WRKSRC}/plugins

.if ${MACHINE_ARCH} == "alpha"
GCC_REQD+=		3.0
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
