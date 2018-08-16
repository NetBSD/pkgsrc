# $NetBSD: Makefile,v 1.17 2018/08/16 18:55:08 adam Exp $
#

DISTNAME=	tcpflow-1.4.5
PKGREVISION=	5
CATEGORIES=	net security
MASTER_SITES=	http://downloads.digitalcorpora.org/downloads/tcpflow/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simsong/tcpflow
COMMENT=	Captures data transmitted as part of TCP connections
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	YES

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -DMAP_FILE=0
CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
