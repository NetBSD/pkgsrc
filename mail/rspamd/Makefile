# $NetBSD: Makefile,v 1.34 2018/02/01 09:58:11 fhajny Exp $

DISTNAME=	rspamd-1.6.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=vstakhov/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://www.rspamd.com/
COMMENT=	Fast, free and open-source spam filtering system
LICENSE=	2-clause-bsd

.include "options.mk"

DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	ragel-[0-9]*:../../devel/ragel

USE_CMAKE=	yes
USE_TOOLS+=	perl pkg-config
USE_LANGUAGES=	c99
BUILD_DEFS+=	VARBASE

LUA_VERSIONS_ACCEPTED=	53

CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/rspamd
TEST_TARGET=	run-test

RSPAMD_USER?=	rspamd
RSPAMD_GROUP?=	rspamd
PKG_GROUPS=	${RSPAMD_GROUP}
PKG_USERS=	${RSPAMD_USER}:${RSPAMD_GROUP}

PKG_GROUPS_VARS=	RSPAMD_GROUP
PKG_USERS_VARS=		RSPAMD_USER

PKG_GECOS.${RSPAMD_USER}=	rspamd user

PKG_SYSCONFSUBDIR=	rspamd
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
LOGDIR=		${VARBASE}/log/rspamd
DBDIR=		${VARBASE}/db/rspamd
RUNDIR=		${VARBASE}/run/rspamd

FILES_SUBST+=	RSPAMD_USER=${RSPAMD_USER}
FILES_SUBST+=	RSPAMD_GROUP=${RSPAMD_GROUP}

RCD_SCRIPTS=	rspamd

CMAKE_ARGS+=	-DMANDIR:PATH=${PREFIX}/${PKGMANDIR}
CMAKE_ARGS+=	-DLOGDIR:PATH=${LOGDIR}
CMAKE_ARGS+=	-DRUNDIR:PATH=${VARBASE}/run/rspamd
CMAKE_ARGS+=	-DDBDIR:PATH=${DBDIR}
CMAKE_ARGS+=	-DCONFDIR:PATH=${PKG_SYSCONFDIR}
CMAKE_ARGS+=	-DRSPAMD_USER=${RSPAMD_USER}
CMAKE_ARGS+=	-DRSPAMD_GROUP=${RSPAMD_GROUP}
CMAKE_ARGS+=	-DENABLE_LUAJIT=OFF
CMAKE_ARGS+=	-DENABLE_SQLITE=ON

REPLACE_PERL+=	utils/rspamd_stats.pl

MAKE_DIRS+=	${PKG_SYSCONFDIR}/modules.d

OWN_DIRS_PERMS+=	${DBDIR} ${RSPAMD_USER} ${RSPAMD_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${RSPAMD_USER} ${RSPAMD_GROUP} 0750
OWN_DIRS_PERMS+=	${RUNDIR} ${RSPAMD_USER} ${RSPAMD_GROUP} 0755

CONF_FILES=	${EGDIR}/2tld.inc ${PKG_SYSCONFDIR}/2tld.inc
CONF_FILES+=	${EGDIR}/common.conf ${PKG_SYSCONFDIR}/common.conf
CONF_FILES+=	${EGDIR}/composites.conf ${PKG_SYSCONFDIR}/composites.conf
CONF_FILES+=	${EGDIR}/dmarc_whitelist.inc ${PKG_SYSCONFDIR}/dmarc_whitelist.inc
CONF_FILES+=	${EGDIR}/logging.inc ${PKG_SYSCONFDIR}/logging.inc
CONF_FILES+=	${EGDIR}/maillist.inc ${PKG_SYSCONFDIR}/maillist.inc
CONF_FILES+=	${EGDIR}/metrics.conf ${PKG_SYSCONFDIR}/metrics.conf
CONF_FILES+=	${EGDIR}/mid.inc ${PKG_SYSCONFDIR}/mic.inc
CONF_FILES+=	${EGDIR}/mime_types.inc ${PKG_SYSCONFDIR}/mime_types.inc
CONF_FILES+=	${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/modules.conf
CONF_FILES+=	${EGDIR}/options.inc ${PKG_SYSCONFDIR}/options.inc
CONF_FILES+=	${EGDIR}/redirectors.inc ${PKG_SYSCONFDIR}/redirectors.inc
CONF_FILES+=	${EGDIR}/rspamd.conf ${PKG_SYSCONFDIR}/rspamd.conf
CONF_FILES+=	${EGDIR}/spf_dkim_whitelist.inc ${PKG_SYSCONFDIR}/spf_dkim_whitelist.inc
CONF_FILES+=	${EGDIR}/statistic.conf ${PKG_SYSCONFDIR}/statistic.conf
CONF_FILES+=	${EGDIR}/surbl-whitelist.inc ${PKG_SYSCONFDIR}/surbl-whitelist.inc
CONF_FILES+=	${EGDIR}/worker-controller.inc ${PKG_SYSCONFDIR}/worker-controller.inc
CONF_FILES+=	${EGDIR}/worker-fuzzy.inc ${PKG_SYSCONFDIR}/worker-fuzzy.inc
CONF_FILES+=	${EGDIR}/worker-normal.inc ${PKG_SYSCONFDIR}/worker-normal.inc
CONF_FILES+=	${EGDIR}/worker-proxy.inc ${PKG_SYSCONFDIR}/worker-proxy.inc
CONF_FILES+=	${EGDIR}/modules.d/antivirus.conf ${PKG_SYSCONFDIR}/modules.d/antivirus.conf
CONF_FILES+=	${EGDIR}/modules.d/arc.conf ${PKG_SYSCONFDIR}/modules.d/arc.conf
CONF_FILES+=	${EGDIR}/modules.d/asn.conf ${PKG_SYSCONFDIR}/modules.d/asn.conf
CONF_FILES+=	${EGDIR}/modules.d/chartable.conf ${PKG_SYSCONFDIR}/modules.d/chartable.conf
CONF_FILES+=	${EGDIR}/modules.d/clickhouse.conf ${PKG_SYSCONFDIR}/modules.d/clickhouse.conf
CONF_FILES+=	${EGDIR}/modules.d/dcc.conf ${PKG_SYSCONFDIR}/modules.d/dcc.conf
CONF_FILES+=	${EGDIR}/modules.d/dkim.conf ${PKG_SYSCONFDIR}/modules.d/dkim.conf
CONF_FILES+=	${EGDIR}/modules.d/dkim_signing.conf ${PKG_SYSCONFDIR}/modules.d/dkim_signing.conf
CONF_FILES+=	${EGDIR}/modules.d/dmarc.conf ${PKG_SYSCONFDIR}/modules.d/dmarc.conf
CONF_FILES+=	${EGDIR}/modules.d/emails.conf ${PKG_SYSCONFDIR}/modules.d/emails.conf
CONF_FILES+=	${EGDIR}/modules.d/fann_redis.conf ${PKG_SYSCONFDIR}/modules.d/fann_redis.conf
CONF_FILES+=	${EGDIR}/modules.d/force_actions.conf ${PKG_SYSCONFDIR}/modules.d/force_actions.conf
CONF_FILES+=	${EGDIR}/modules.d/forged_recipients.conf ${PKG_SYSCONFDIR}/modules.d/forged_recipients.conf
CONF_FILES+=	${EGDIR}/modules.d/fuzzy_check.conf ${PKG_SYSCONFDIR}/modules.d/fuzzy_check.conf
CONF_FILES+=	${EGDIR}/modules.d/greylist.conf ${PKG_SYSCONFDIR}/modules.d/greylist.conf
CONF_FILES+=	${EGDIR}/modules.d/hfilter.conf ${PKG_SYSCONFDIR}/modules.d/hfilter.conf
CONF_FILES+=	${EGDIR}/modules.d/ip_score.conf ${PKG_SYSCONFDIR}/modules.d/ip_score.conf
CONF_FILES+=	${EGDIR}/modules.d/maillist.conf ${PKG_SYSCONFDIR}/modules.d/maillist.conf
CONF_FILES+=	${EGDIR}/modules.d/metadata_exporter.conf ${PKG_SYSCONFDIR}/modules.d/metadata_exporter.conf
CONF_FILES+=	${EGDIR}/modules.d/metric_exporter.conf ${PKG_SYSCONFDIR}/modules.d/metric_exporter.conf
CONF_FILES+=	${EGDIR}/modules.d/mid.conf ${PKG_SYSCONFDIR}/modules.d/mid.conf
CONF_FILES+=	${EGDIR}/modules.d/milter_headers.conf ${PKG_SYSCONFDIR}/modules.d/milter_headers.conf
CONF_FILES+=	${EGDIR}/modules.d/mime_types.conf ${PKG_SYSCONFDIR}/modules.d/mime_types.conf
CONF_FILES+=	${EGDIR}/modules.d/multimap.conf ${PKG_SYSCONFDIR}/modules.d/multimap.conf
CONF_FILES+=	${EGDIR}/modules.d/mx_check.conf ${PKG_SYSCONFDIR}/modules.d/mx_check.conf
CONF_FILES+=	${EGDIR}/modules.d/once_received.conf ${PKG_SYSCONFDIR}/modules.d/once_received.conf
CONF_FILES+=	${EGDIR}/modules.d/phishing.conf ${PKG_SYSCONFDIR}/modules.d/phishing.conf
CONF_FILES+=	${EGDIR}/modules.d/ratelimit.conf ${PKG_SYSCONFDIR}/modules.d/ratelimit.conf
CONF_FILES+=	${EGDIR}/modules.d/rbl.conf ${PKG_SYSCONFDIR}/modules.d/rbl.conf
CONF_FILES+=	${EGDIR}/modules.d/redis.conf ${PKG_SYSCONFDIR}/modules.d/redis.conf
CONF_FILES+=	${EGDIR}/modules.d/regexp.conf ${PKG_SYSCONFDIR}/modules.d/regexp.conf
CONF_FILES+=	${EGDIR}/modules.d/replies.conf ${PKG_SYSCONFDIR}/modules.d/replies.conf
CONF_FILES+=	${EGDIR}/modules.d/rspamd_update.conf ${PKG_SYSCONFDIR}/modules.d/rspamd_update.conf
CONF_FILES+=	${EGDIR}/modules.d/spamassassin.conf ${PKG_SYSCONFDIR}/modules.d/spamassassin.conf
CONF_FILES+=	${EGDIR}/modules.d/spamtrap.conf ${PKG_SYSCONFDIR}/modules.d/spamtrap.conf
CONF_FILES+=	${EGDIR}/modules.d/spf.conf ${PKG_SYSCONFDIR}/modules.d/spf.conf
CONF_FILES+=	${EGDIR}/modules.d/surbl.conf ${PKG_SYSCONFDIR}/modules.d/surbl.conf
CONF_FILES+=	${EGDIR}/modules.d/trie.conf ${PKG_SYSCONFDIR}/modules.d/trie.conf
CONF_FILES+=	${EGDIR}/modules.d/url_redirector.conf ${PKG_SYSCONFDIR}/modules.d/url_redirector.conf
CONF_FILES+=	${EGDIR}/modules.d/url_reputation.conf ${PKG_SYSCONFDIR}/modules.d/url_reputation.conf
CONF_FILES+=	${EGDIR}/modules.d/url_tags.conf ${PKG_SYSCONFDIR}/modules.d/url_tags.conf
CONF_FILES+=	${EGDIR}/modules.d/whitelist.conf ${PKG_SYSCONFDIR}/modules.d/whitelist.conf

post-extract:
	${FIND} ${WRKSRC}/conf -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/conf -type f -exec ${CHMOD} ${DOCMODE} {} \;

.include "../../databases/hiredis/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/fann/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
