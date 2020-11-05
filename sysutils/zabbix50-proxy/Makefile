# $NetBSD: Makefile,v 1.2 2020/11/05 09:09:12 ryoon Exp $

PKGREVISION= 1
.include "../../sysutils/zabbix50-server/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-proxy-${ZABBIX_DB_TYPE}-/}
COMMENT=	Enterprise-class Monitoring Solution for Everyone

CONFLICTS+=	zabbix-[0-9]*
CONFLICTS+=	zabbix-proxy-[0-9]*

DEPENDS+=	fping-[0-9]*:../../net/fping

USE_TOOLS+=		aclocal autoconf automake pax pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-proxy
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-libcurl
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
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
SUBST_FILES.fix-pkgbase=	src/zabbix_proxy/Makefile.am
SUBST_SED.fix-pkgbase=		-e 's,%%PKGBASE%%,${PKGBASE},g'

PLIST_SUBST+=			PKGBASE=${PKGBASE}

CFLAGS.SunOS+=			-DDUK_USE_BYTEORDER=1

.include "../../mk/bsd.prefs.mk"

pre-configure:
	set -e; cd ${WRKSRC}; \
	   aclocal -I m4 ; automake -ai --foreign; autoconf -I m4

post-install:
	cd ${WRKSRC}/database/${ZABBIX_DB_TYPE}; \
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
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
