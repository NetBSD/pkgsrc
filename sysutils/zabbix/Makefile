# $NetBSD: Makefile,v 1.37 2020/06/20 12:43:46 gdt Exp $

#PKGREVISION= 1
.include "Makefile.common"

COMMENT=	Enterprise-class Monitoring Solution for Everyone

DEPENDS+=	fping-[0-9]*:../../net/fping

USE_TOOLS+=		pax pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-agent
CONFIGURE_ARGS+=	--enable-proxy
CONFIGURE_ARGS+=	--enable-server
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-jabber
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-libcurl
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

EGDIR=		share/examples/zabbix
CONF_FILES+=	${EGDIR}/zabbix_agentd.conf ${PKG_SYSCONFDIR}/zabbix_agentd.conf
CONF_FILES+=	${EGDIR}/zabbix_proxy.conf ${PKG_SYSCONFDIR}/zabbix_proxy.conf
CONF_FILES+=	${EGDIR}/zabbix_server.conf ${PKG_SYSCONFDIR}/zabbix_server.conf

RCD_SCRIPTS=	zabbix_agentd zabbix_proxy zabbix_server

INSTALLATION_DIRS+=	${EGDIR} share/zabbix

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		conf/*.conf
SUBST_FILES.fix-paths+=		man/*.man
SUBST_SED.fix-paths=		-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'

.include "../../mk/bsd.prefs.mk"

ZABBIX_GROUP?=		zabbix
ZABBIX_USER?=		zabbix
PKG_GROUPS+=		${ZABBIX_GROUP}
PKG_USERS+=		${ZABBIX_USER}:${ZABBIX_GROUP}
PKG_GECOS.${ZABBIX_USER}= Zabbix user

FILES_SUBST+=		ZABBIX_USER=${ZABBIX_USER}
FILES_SUBST+=		ZABBIX_GROUP=${ZABBIX_GROUP}

SMF_INSTANCES=		agent proxy server

post-install:
	cd ${WRKSRC}/database/${ZABBIX_DB_TYPE}; \
		${PAX} -rw . ${DESTDIR}${PREFIX}/share/zabbix/
	rm ${DESTDIR}${PREFIX}/share/zabbix/Makefile*

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/iksemel/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
