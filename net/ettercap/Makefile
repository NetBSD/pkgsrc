# $NetBSD: Makefile,v 1.4.2.1 2002/06/23 18:55:13 jlam Exp $

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
USE_PTHREAD=		native pth

CPPFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib

post-install:
			cd ${WRKSRC}/plugins ; ${MAKE_ENV} ${MAKE} install

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
