# $NetBSD: Makefile,v 1.12 2024/05/29 16:34:33 adam Exp $

PKGREVISION= 2
.include "../../sysutils/zabbix60-server/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-proxy-${ZABBIX_DB_TYPE}-/}
COMMENT=	Enterprise-class Monitoring Solution for Everyone

PATCHDIR=	${.CURDIR}/../../sysutils/zabbix60-server/patches
DISTINFO_FILE=	${.CURDIR}/../../sysutils/zabbix60-server/distinfo

CONFLICTS+=	zabbix-[0-9]*
CONFLICTS+=	zabbix-proxy-[0-9]*

DEPENDS+=	fping-[0-9]*:../../net/fping

USE_TOOLS+=		pax pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-proxy
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-libcurl
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-libpcre2=${BUILDLINK_PREFIX.pcre2}
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

EGDIR=		share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/zabbix_proxy.conf ${PKG_SYSCONFDIR}/zabbix_proxy.conf

RCD_SCRIPTS=	zabbix_proxy
SMF_NAME=	zabbix-proxy

INSTALLATION_DIRS+=	${EGDIR} share/${PKGBASE}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		conf/*.conf
SUBST_FILES.fix-paths+=		man/*.man
SUBST_SED.fix-paths=		-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=			fix-pkgbase
SUBST_STAGE.fix-pkgbase=	pre-configure
SUBST_MESSAGE.fix-pkgbase=	Fixing PKGBASE.
SUBST_FILES.fix-pkgbase=	src/zabbix_proxy/Makefile.*
SUBST_SED.fix-pkgbase=		-e 's,%%PKGBASE%%,${PKGBASE},g'

SUBST_CLASSES+=			fix-popcount
SUBST_STAGE.fix-popcount=	post-patch
SUBST_MESSAGE.fix-popcount=	Fix conflict with NetBSD's popcount.
SUBST_FILES.fix-popcount+=	src/zabbix_server/lld/lld_host.c
SUBST_SED.fix-popcount+=	-e 's,popcount,zbx_popcount,g'

PLIST_SUBST+=			PKGBASE=${PKGBASE}

CFLAGS.SunOS+=			-DDUK_USE_BYTEORDER=1 -D__EXTENSIONS__

.include "../../mk/bsd.prefs.mk"

post-install:
	cd ${WRKSRC}/database/${ZABBIX_DB_TYPE} && \
		${PAX} -rw . ${DESTDIR}${PREFIX}/share/${PKGBASE}/
	${RM} ${DESTDIR}${PREFIX}/share/${PKGBASE}/Makefile*
	${RM} ${DESTDIR}${PREFIX}/share/${PKGBASE}/data.sql
	${RM} ${DESTDIR}${PREFIX}/share/${PKGBASE}/images.sql
	${MV} ${DESTDIR}${PREFIX}/bin/zabbix_js \
	   ${DESTDIR}${PREFIX}/bin/zabbix_proxy_js

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
