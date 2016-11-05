# $NetBSD: Makefile,v 1.21 2016/11/05 10:34:25 wiz Exp $

DISTNAME=	rspamd-1.3.5
CATEGORIES=	mail
MASTER_SITES=	http://www.rspamd.com/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://www.rspamd.com/
COMMENT=	Fast, free and open-source spam filtering system
LICENSE=	2-clause-bsd

DEPENDS+=	ragel-[0-9]*:../../devel/ragel

USE_CMAKE=	yes
USE_TOOLS+=	perl:run pkg-config
USE_LANGUAGES=	c99
CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/rspamd
TEST_TARGET=	run-test

PKG_SYSCONFSUBDIR=	rspamd
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

CMAKE_ARGS+=	-DMANDIR:PATH=${PREFIX}/${PKGMANDIR}
CMAKE_ARGS+=	-DCONFDIR:PATH=${EGDIR}
CMAKE_ARGS+=	-DENABLE_LUAJIT=OFF

REPLACE_PERL+=	utils/rspamd_stats.pl

MAKE_DIRS+=	${PKG_SYSCONFDIR}/modules.d

CONF_FILES=	${EGDIR}/2tld.inc ${PKG_SYSCONFDIR}/2tld.inc
CONF_FILES+=	${EGDIR}/common.conf ${PKG_SYSCONFDIR}/common.conf
CONF_FILES+=	${EGDIR}/composites.conf ${PKG_SYSCONFDIR}/composites.conf
CONF_FILES+=	${EGDIR}/logging.inc ${PKG_SYSCONFDIR}/logging.inc
CONF_FILES+=	${EGDIR}/metrics.conf ${PKG_SYSCONFDIR}/metrics.conf
CONF_FILES+=	${EGDIR}/mime_types.inc ${PKG_SYSCONFDIR}/mime_types.inc
CONF_FILES+=	${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/modules.conf
CONF_FILES+=	${EGDIR}/modules.d/chartable.conf ${PKG_SYSCONFDIR}/modules.d/chartable.conf
CONF_FILES+=	${EGDIR}/modules.d/dkim.conf ${PKG_SYSCONFDIR}/modules.d/dkim.conf
CONF_FILES+=	${EGDIR}/modules.d/dmarc.conf ${PKG_SYSCONFDIR}/modules.d/dmarc.conf
CONF_FILES+=	${EGDIR}/modules.d/emails.conf ${PKG_SYSCONFDIR}/modules.d/emails.conf
CONF_FILES+=	${EGDIR}/modules.d/forged_recipients.conf ${PKG_SYSCONFDIR}/modules.d/forged_recipients.conf
CONF_FILES+=	${EGDIR}/modules.d/fuzzy_check.conf ${PKG_SYSCONFDIR}/modules.d/fuzzy_check.conf
CONF_FILES+=	${EGDIR}/modules.d/hfilter.conf ${PKG_SYSCONFDIR}/modules.d/hfilter.conf
CONF_FILES+=	${EGDIR}/modules.d/ip_score.conf ${PKG_SYSCONFDIR}/modules.d/ip_score.conf
CONF_FILES+=	${EGDIR}/modules.d/maillist.conf ${PKG_SYSCONFDIR}/modules.d/maillist.conf
CONF_FILES+=	${EGDIR}/modules.d/mime_types.conf ${PKG_SYSCONFDIR}/modules.d/mime_types.conf
CONF_FILES+=	${EGDIR}/modules.d/multimap.conf ${PKG_SYSCONFDIR}/modules.d/multimap.conf
CONF_FILES+=	${EGDIR}/modules.d/once_received.conf ${PKG_SYSCONFDIR}/modules.d/once_received.conf
CONF_FILES+=	${EGDIR}/modules.d/phishing.conf ${PKG_SYSCONFDIR}/modules.d/phishing.conf
CONF_FILES+=	${EGDIR}/modules.d/ratelimit.conf ${PKG_SYSCONFDIR}/modules.d/ratelimit.conf
CONF_FILES+=	${EGDIR}/modules.d/rbl.conf ${PKG_SYSCONFDIR}/modules.d/rbl.conf
CONF_FILES+=	${EGDIR}/modules.d/regexp.conf ${PKG_SYSCONFDIR}/modules.d/regexp.conf
CONF_FILES+=	${EGDIR}/modules.d/rspamd_update.conf ${PKG_SYSCONFDIR}/modules.d/rspamd_update.conf
CONF_FILES+=	${EGDIR}/modules.d/spf.conf ${PKG_SYSCONFDIR}/modules.d/spf.conf
CONF_FILES+=	${EGDIR}/modules.d/surbl.conf ${PKG_SYSCONFDIR}/modules.d/surbl.conf
CONF_FILES+=	${EGDIR}/modules.d/whitelist.conf ${PKG_SYSCONFDIR}/modules.d/whitelist.conf
CONF_FILES+=	${EGDIR}/options.inc ${PKG_SYSCONFDIR}/options.inc
CONF_FILES+=	${EGDIR}/redirectors.inc ${PKG_SYSCONFDIR}/redirectors.inc
CONF_FILES+=	${EGDIR}/rspamd.conf ${PKG_SYSCONFDIR}/rspamd.conf
CONF_FILES+=	${EGDIR}/rspamd.systemd.conf ${PKG_SYSCONFDIR}/rspamd.systemd.conf
CONF_FILES+=	${EGDIR}/rspamd.sysvinit.conf ${PKG_SYSCONFDIR}/rspamd.sysvinit.conf
CONF_FILES+=	${EGDIR}/statistic.conf ${PKG_SYSCONFDIR}/statistic.conf
CONF_FILES+=	${EGDIR}/spf_dkim_whitelist.inc ${PKG_SYSCONFDIR}/spf_dkim_whitelist.inc
CONF_FILES+=	${EGDIR}/surbl-whitelist.inc ${PKG_SYSCONFDIR}/surbl-whitelist.inc
CONF_FILES+=	${EGDIR}/worker-controller.inc ${PKG_SYSCONFDIR}/worker-controller.inc
CONF_FILES+=	${EGDIR}/worker-fuzzy.inc ${PKG_SYSCONFDIR}/worker-fuzzy.inc
CONF_FILES+=	${EGDIR}/worker-normal.inc ${PKG_SYSCONFDIR}/worker-normal.inc

post-extract:
	${FIND} ${WRKSRC}/conf -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/conf -type f -exec ${CHMOD} ${DOCMODE} {} \;

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../databases/hiredis/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
