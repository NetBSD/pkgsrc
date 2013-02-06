# $NetBSD: Makefile,v 1.17 2013/02/06 19:31:01 jperkin Exp $

DISTNAME=	tcpd-tools-0.8
PKGNAME=	tcpdstat-0.8
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# ftp://tracer.csl.sony.co.jp/pub/mawi/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Analyze tcpdump output

NOT_FOR_PLATFORM=	Interix-*-*

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
