# $NetBSD: Makefile,v 1.21 2003/11/12 03:39:41 jschauma Exp $

DISTNAME=		ettercap-0.6.9
PKGREVISION=		5
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
