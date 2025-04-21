# $NetBSD: Makefile,v 1.18 2025/04/21 21:09:45 wiz Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdstat-0.8
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Analyze tcpdump output

CFLAGS.SunOS+=	-Du_int64_t=uint64_t -Du_int32_t=uint32_t
CFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int8_t=uint8_t

LIBS.SunOS+=	-lsocket -lnsl

MAKE_ENV+=	SYS_LIBS=${LIBS:Q}

WRKSRC=		${WRKDIR}/${DISTNAME}/tcpdstat

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdstat ${DESTDIR}${PREFIX}/bin

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
