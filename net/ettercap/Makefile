# $NetBSD: Makefile,v 1.7 2002/10/13 12:15:05 wiz Exp $

DISTNAME=		ettercap-0.6.6.6
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
