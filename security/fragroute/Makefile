# $NetBSD: Makefile,v 1.2 2004/04/25 05:02:23 snj Exp $
# FreeBSD Id: ports/security/fragroute/Makefile,v 1.10 2003/09/24 08:37:38 edwin Exp

DISTNAME=	fragroute-1.2
CATEGORIES=	security net
MASTER_SITES=	http://monkey.org/~dugsong/fragroute/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.monkey.org/~dugsong/fragroute/
COMMENT=        Tool for intercepting, modifying and rewriting egress traffic

USE_BUILDLINK3=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-libdnet=${PREFIX}
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-pcap=${BUILDLINK_PREFIX.libpcap}

SCRIPTS=	README.snort base-1 frag-1 frag-2 frag-3 frag-4 frag-5 \
	frag-6 frag-7-unix frag-7-win32 ins-2 ins-3 tcbc-2 tcp-3 tcp-5 \
	tcp-7 tcp-9

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/fragroute
.for FILE in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/scripts/${FILE} ${PREFIX}/share/fragroute
.endfor

.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
