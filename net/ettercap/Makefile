# $NetBSD: Makefile,v 1.6 2002/08/01 05:48:18 jlam Exp $

DISTNAME=		ettercap-0.6.6.6
CATEGORIES=		security net
MASTER_SITES=		http://ettercap.sourceforge.net/download/

MAINTAINER=		nk@bsdirc.net
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-plugins \
			--enable-https

# missing newpad()
USE_NCURSES=		yes
PTHREAD_OPTS+=		require

CPPFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib

post-install:
			cd ${WRKSRC}/plugins ; ${MAKE_ENV} ${MAKE} install

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
