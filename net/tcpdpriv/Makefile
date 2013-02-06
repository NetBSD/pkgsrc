# $NetBSD: Makefile,v 1.20 2013/02/06 19:31:00 jperkin Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdpriv-0.8
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Anonymize tcpdump traces

CFLAGS.SunOS+=	-DSVR4 -DIPPROTO_IPV4=IPPROTO_ENCAP -DIP_OFFMASK=0x1fff
CFLAGS.SunOS+=	-DARPOP_REVREQUEST=REVARP_REQUEST -DARPOP_REVREPLY=REVARP_REPLY
CFLAGS.SunOS+=	-Du_int64_t=uint64_t -Du_int32_t=uint32_t
CFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int8_t=uint8_t

WRKSRC=		${WRKDIR}/${DISTNAME}/wide-tcpdpriv

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdpriv ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpdpriv.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
