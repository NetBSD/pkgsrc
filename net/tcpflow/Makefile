# $NetBSD: Makefile,v 1.19 2018/11/14 22:22:14 kleink Exp $

DISTNAME=	tcpflow-1.5.0
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://downloads.digitalcorpora.org/downloads/tcpflow/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simsong/tcpflow
COMMENT=	Captures data transmitted as part of TCP connections
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-o3

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -DMAP_FILE=0
CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
