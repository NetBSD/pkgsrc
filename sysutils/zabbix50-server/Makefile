# $NetBSD: Makefile,v 1.24 2024/05/16 06:15:37 wiz Exp $
# used by sysutils/zabbix50-proxy/Makefile
# used by sysutils/zabbix50-agent/Makefile
#

PKGREVISION= 1
.include "Makefile.common"

PKGNAME=	${DISTNAME:S/-/-server-${ZABBIX_DB_TYPE}-/}
COMMENT=	Enterprise-class Monitoring Solution for Everyone

CONFLICTS+=	zabbix-[0-9]*
CONFLICTS+=	zabbix-server-[0-9]*

DEPENDS+=	fping-[0-9]*:../../net/fping

USE_TOOLS+=		aclocal autoconf automake pax pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-server
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
CONF_FILES+=	${EGDIR}/zabbix_server.conf ${PKG_SYSCONFDIR}/zabbix_server.conf

RCD_SCRIPTS=	zabbix_server
SMF_NAME=	zabbix-server

MISCDIRS=	images snmptrap

INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	share/${PKGBASE}
.for MISCDIR in ${MISCDIRS}
INSTALLATION_DIRS+=	share/${PKGBASE}/misc/${MISCDIR}
.endfor

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		conf/*.conf
SUBST_FILES.fix-paths+=		man/*.man
SUBST_SED.fix-paths=		-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=			fix-pkgbase
SUBST_STAGE.fix-pkgbase=	pre-configure
SUBST_MESSAGE.fix-pkgbase=	Fixing PKGBASE.
SUBST_FILES.fix-pkgbase=	src/zabbix_server/Makefile.*
SUBST_SED.fix-pkgbase=		-e 's,%%PKGBASE%%,${PKGBASE},g'

PLIST_SUBST+=			PKGBASE=${PKGBASE}

CFLAGS.SunOS+=			-DDUK_USE_BYTEORDER=1

REPLACE_BASH+=			misc/snmptrap/snmptrap.sh \
				misc/images/png_to_xml.sh

.include "../../mk/bsd.prefs.mk"

pre-configure:
	cd ${WRKSRC} && \
	   aclocal -I m4 && automake -ai --foreign && autoconf -I m4

post-install:
	cd ${WRKSRC}/database/${ZABBIX_DB_TYPE} && \
		${PAX} -rw . ${DESTDIR}${PREFIX}/share/${PKGBASE}/
.for MISCDIR in ${MISCDIRS}
	cd ${WRKSRC}/misc/${MISCDIR}; \
		${PAX} -rw . ${DESTDIR}${PREFIX}/share/${PKGBASE}/misc/${MISCDIR}
.endfor
	${RM} ${DESTDIR}${PREFIX}/share/${PKGBASE}/Makefile*

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
