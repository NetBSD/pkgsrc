# $NetBSD: Makefile,v 1.13 2017/08/24 20:03:36 adam Exp $

DISTNAME=	ntopng-2.4-stable
PKGNAME=	ntopng-2.4
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ntop/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ntop.org/
COMMENT=	Network traffic probe
LICENSE=	gnu-gpl-v3

DEPENDS+=	redis-[0-9]*:../../databases/redis

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes

RCD_SCRIPTS+=		ntopng

SUBST_CLASSES+=		fix-vers
SUBST_STAGE.fix-vers=	pre-configure
SUBST_MESSAGE.fix-vers=	Setting package version.
SUBST_FILES.fix-vers=	configure.seed
SUBST_SED.fix-vers=	-e 's,@VERSION@,${PKGVERSION},g'
SUBST_SED.fix-vers+=	-e 's,@SHORT_VERSION@,${PKGVERSION_NOREV},g'

# Portable types
CFLAGS.SunOS+=		-Du_int8_t=uint8_t
CFLAGS.SunOS+=		-Du_int16_t=uint16_t
CFLAGS.SunOS+=		-Du_int32_t=uint32_t
CFLAGS.SunOS+=		-Du_int64_t=uint64_t

LDFLAGS.SunOS+=		-lresolv

pre-configure:
	cd ${WRKSRC} && cp configure.seed configure.ac && autoreconf -fiv

.include "../../databases/hiredis/buildlink3.mk"
.include "../../databases/rrdtool/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/ndpi/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
