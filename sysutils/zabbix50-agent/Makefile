# $NetBSD: Makefile,v 1.25 2024/05/29 16:34:33 adam Exp $

PKGREVISION= 2
.include "../../sysutils/zabbix50-server/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-agent-/}
COMMENT=	Enterprise-class Monitoring Solution for Everyone

PATCHDIR=	${.CURDIR}/../../sysutils/zabbix50-server/patches
DISTINFO_FILE=	${.CURDIR}/../../sysutils/zabbix50-server/distinfo

CONFLICTS+=	zabbix-[0-9]*
CONFLICTS+=	zabbix-agent-[0-9]*

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-agent
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--with-libcurl
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

EGDIR=		share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/zabbix_agentd.conf ${PKG_SYSCONFDIR}/zabbix_agentd.conf

RCD_SCRIPTS=	zabbix_agentd
SMF_NAME=	zabbix-agent

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
SUBST_FILES.fix-pkgbase=	src/zabbix_agent/Makefile.in
SUBST_SED.fix-pkgbase=		-e 's,%%PKGBASE%%,${PKGBASE},g'

PLIST_SUBST+=			PKGBASE=${PKGBASE}

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
