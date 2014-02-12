# $NetBSD: Makefile,v 1.26 2014/02/12 23:18:31 tron Exp $

DISTNAME=	fragroute-1.2
PKGREVISION=	16
CATEGORIES=	security net
MASTER_SITES=	http://monkey.org/~dugsong/fragroute/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.monkey.org/~dugsong/fragroute/
COMMENT=	Tool for intercepting, modifying and rewriting egress traffic

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-libdnet=${BUILDLINK_PREFIX.libdnet}
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-pcap=${BUILDLINK_PREFIX.libpcap}

SCRIPTS=	README.snort base-1 frag-1 frag-2 frag-3 frag-4 frag-5 \
	frag-6 frag-7-unix frag-7-win32 ins-2 ins-3 tcbc-2 tcp-3 tcp-5 \
	tcp-7 tcp-9

INSTALLATION_DIRS+=	share/fragroute

pre-install:
.for file in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/scripts/${file} ${DESTDIR}${PREFIX}/share/fragroute
.endfor

.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
