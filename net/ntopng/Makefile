# $NetBSD: Makefile,v 1.71 2024/05/29 16:34:00 adam Exp $

DISTNAME=	ntopng-6.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ntop/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.ntop.org/
COMMENT=	Network traffic probe
LICENSE=	gnu-gpl-v3

DEPENDS+=	redis-[0-9]*:../../databases/redis

# How to rebuild UI after bumping version:
# 1. install lang/nodejs
# 2. comment out the DISTFILES=... line
# 3. run "make distinfo extract update-ui"
# 4. publish the resulting distfile on MASTER_SITE_LOCAL
# 5. uncomment the DISTFILES=... line and regen distinfo
.PHONY: update-ui
update-ui:
	cd ${WRKSRC} && npm install && npm run build && \
	cd .. && ${TAR} -czf ${HTTPDOCS_DIST} ${DISTNAME}/httpdocs/dist && \
	${CP} ${HTTPDOCS_DIST} ${DISTDIR}/${HTTPDOCS_DIST} && \
	${ECHO} "UI built. Run this command:" && \
	${ECHO} "# scp ${DISTDIR}/${HTTPDOCS_DIST} ftp.netbsd.org:/pub/pkgsrc/distfiles/LOCAL_PORTS/."

HTTPDOCS_DIST=		${DISTNAME}-httpdocs.tar.gz
SITES.${HTTPDOCS_DIST}=	${MASTER_SITE_LOCAL}
# comment out this when running make update-ui
DISTFILES=		${DEFAULT_DISTFILES} ${HTTPDOCS_DIST}

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake bash gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ndpi-includes=${BUILDLINK_PREFIX.ndpi}/include/ndpi
CONFIGURE_ARGS+=	--with-ndpi-static-lib=${BUILDLINK_PREFIX.ndpi}/lib

RCD_SCRIPTS+=		ntopng

MAKE_FLAGS+=		LUA_LIB=-llua5.4

# Portable types
CFLAGS.SunOS+=		-Du_int8_t=uint8_t
CFLAGS.SunOS+=		-Du_int16_t=uint16_t
CFLAGS.SunOS+=		-Du_int32_t=uint32_t
CFLAGS.SunOS+=		-Du_int64_t=uint64_t
LDFLAGS.SunOS+=		-lresolv

REPLACE_BASH=		httpdocs/misc/ntopng-add-user.sh
REPLACE_BASH+=		httpdocs/misc/ntopng-utils-manage-config.in

SUBST_CLASSES+=		fix-vers
SUBST_STAGE.fix-vers=	pre-configure
SUBST_MESSAGE.fix-vers=	Setting package version.
SUBST_FILES.fix-vers=	configure.ac.in
SUBST_SED.fix-vers=	-e 's,@VERSION@,${PKGVERSION},g'
SUBST_SED.fix-vers+=	-e 's,@SHORT_VERSION@,${PKGVERSION_NOREV},g'

pre-configure:
	cd ${WRKSRC} && ${CP} configure.ac.in configure.ac && autoreconf -fiv

post-build:
	${FIND} ${WRKSRC}/httpdocs -type f -print0 | xargs -0 chmod a-x

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/ntopng/httpdocs/misc/ntopng-utils-manage-updates.in.orig

.include "../../archivers/zstd/buildlink3.mk"
.include "../../databases/hiredis/buildlink3.mk"
.include "../../databases/rrdtool/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/ndpi/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
