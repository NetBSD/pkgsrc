# $NetBSD: Makefile,v 1.23 2013/02/06 23:23:36 jperkin Exp $

DISTNAME=	fragroute-1.2
PKGREVISION=	14
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
.for FILE in ${SCRIPTS}
	${INSTALL_DATA} ${WRKSRC}/scripts/${FILE} ${DESTDIR}${PREFIX}/share/fragroute
.endfor

.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
