# $NetBSD: Makefile,v 1.12 2003/05/02 11:56:01 wiz Exp $

DISTNAME=		ettercap-0.6.9
PKGREVISION=	1
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

post-build:
			cd ${WRKSRC}/plugins ; ${MAKE_ENV} ${MAKE} all

post-install:
			cd ${WRKSRC}/plugins ; ${MAKE_ENV} ${MAKE} install

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
