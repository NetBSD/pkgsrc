# $NetBSD: Makefile,v 1.23 2004/01/23 23:38:13 wiz Exp $

DISTNAME=		ettercap-0.6.b
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

USE_BUILDLINK2=		yes

USE_NCURSES=		# MAX_FORM_COMMAND
PTHREAD_OPTS+=		require
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}
LIBS+=			-ldes

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/plugins
INSTALL_DIRS=		${WRKSRC} ${WRKSRC}/plugins

.if ${MACHINE_ARCH} == "alpha"
GCC_REQD=		3.0
.endif

post-buildlink:
	if [ ! -f /usr/include/des.h ]; then \
		${LN} -s ${BUILDLINK_DIR}/include/openssl/des.h \
			${BUILDLINK_DIR}/include; \
	fi

.include "../../devel/ncurses/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
