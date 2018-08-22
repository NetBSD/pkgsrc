# $NetBSD: Makefile,v 1.45 2018/08/22 09:45:34 wiz Exp $

DISTNAME=	rspamd-1.7.8
PKGREVISION=	1
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
CMAKE_ARGS+=	-DENABLE_SQLITE=ON
# Torch requires LuaJIT2, but LuaJIT2 only supports Lua 5.1
CMAKE_ARGS+=	-DENABLE_LUAJIT=OFF
CMAKE_ARGS+=	-DENABLE_TORCH=OFF

REPLACE_PERL+=	utils/rspamd_stats.pl

MAKE_DIRS+=	${PKG_SYSCONFDIR}/modules.d

OWN_DIRS_PERMS+=	${DBDIR} ${RSPAMD_USER} ${RSPAMD_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${RSPAMD_USER} ${RSPAMD_GROUP} 0750
OWN_DIRS_PERMS+=	${RUNDIR} ${RSPAMD_USER} ${RSPAMD_GROUP} 0755

CFGFILES=	2tld.inc actions.conf common.conf composites.conf \
		dmarc_whitelist.inc groups.conf logging.inc \
		maillist.inc metrics.conf mid.inc mime_types.inc \
		modules.conf modules.d/antivirus.conf modules.d/arc.conf \
		modules.d/asn.conf modules.d/clickhouse.conf \
		modules.d/dcc.conf modules.d/dkim_signing.conf \
		modules.d/dkim.conf modules.d/dmarc.conf \
		modules.d/elastic.conf modules.d/emails.conf \
		modules.d/force_actions.conf \
		modules.d/forged_recipients.conf \
		modules.d/fuzzy_check.conf modules.d/greylist.conf \
		modules.d/hfilter.conf modules.d/history_redis.conf \
		modules.d/chartable.conf modules.d/ip_score.conf \
		modules.d/maillist.conf modules.d/metadata_exporter.conf \
		modules.d/metric_exporter.conf modules.d/mid.conf \
		modules.d/milter_headers.conf modules.d/mime_types.conf \
		modules.d/multimap.conf modules.d/mx_check.conf \
		modules.d/neural.conf modules.d/once_received.conf \
		modules.d/phishing.conf modules.d/ratelimit.conf \
		modules.d/rbl.conf modules.d/redis.conf \
		modules.d/regexp.conf modules.d/replies.conf \
		modules.d/rspamd_update.conf modules.d/spamassassin.conf \
		modules.d/spamtrap.conf modules.d/spf.conf \
		modules.d/surbl.conf modules.d/trie.conf \
		modules.d/url_redirector.conf modules.d/url_reputation.conf \
		modules.d/url_tags.conf modules.d/whitelist.conf \
		options.inc redirectors.inc rspamd.conf \
		scores.d/fuzzy_group.conf scores.d/headers_group.conf \
		scores.d/hfilter_group.conf scores.d/mime_types_group.conf \
		scores.d/mua_group.conf scores.d/phishing_group.conf \
		scores.d/policies_group.conf scores.d/rbl_group.conf \
		scores.d/statistics_group.conf scores.d/subject_group.conf \
		scores.d/surbl_group.conf spf_dkim_whitelist.inc \
		statistic.conf surbl-whitelist.inc worker-controller.inc \
		worker-fuzzy.inc worker-normal.inc worker-proxy.inc

.for file in ${CFGFILES}
CONF_FILES=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

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
