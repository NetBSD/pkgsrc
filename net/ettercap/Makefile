# $NetBSD: Makefile,v 1.27 2004/03/31 07:12:21 xtraeme Exp $

DISTNAME=		ettercap-0.6.b
PKGREVISION=		1
CATEGORIES=		security net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ettercap/} \
			http://ettercap.sourceforge.net/download/

MAINTAINER=		nk@bsdirc.net
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-plugins \
			--enable-https \
			--disable-gtk

USE_BUILDLINK3=		yes

USE_NCURSES=		# putwin(), pechochar()
PTHREAD_OPTS+=		require
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}
LIBS+=			-ldes ${PTHREAD_LDFLAGS}

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/plugins
INSTALL_DIRS=		${WRKSRC} ${WRKSRC}/plugins

.if ${MACHINE_ARCH} == "alpha"
GCC_REQD+=		3.0
.endif

post-buildlink:
	if [ ! -f /usr/include/des.h ]; then \
		${LN} -s ${BUILDLINK_DIR}/include/openssl/des.h \
			${BUILDLINK_DIR}/include; \
	fi

.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
