# $NetBSD: Makefile,v 1.8 2002/11/19 21:07:57 agc Exp $

DISTNAME=		ettercap-0.6.7
CATEGORIES=		security net
MASTER_SITES=		http://ettercap.sourceforge.net/download/

MAINTAINER=		nk@bsdirc.net
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-plugins \
			--enable-https

USE_BUILDLINK2=		yes

# missing newpad()
USE_NCURSES=		yes
PTHREAD_OPTS+=		require

post-install:
			cd ${WRKSRC}/plugins ; ${MAKE_ENV} ${MAKE} install

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
