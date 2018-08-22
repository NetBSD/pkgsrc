# $NetBSD: Makefile,v 1.24 2018/08/22 09:46:31 wiz Exp $

.include "../../sysutils/collectd/Makefile.common"

PKGREVISION=	2

COMMENT=	Statistics collection daemon base

RCD_SCRIPTS=	collectd

.include "../../mk/bsd.prefs.mk"

# Simple plugins that have no dependencies
DEFAULT_PLUGINS+=	aggregation apcups csv email exec filecount	\
			hddtemp logfile match_empty_counter match_hashed\
			match_regex match_timediff match_value mbmon	\
			ntpd olsrd openvpn powerdns statsd table tail	\
			tail_csv target_notification target_replace	\
			target_scale target_set	target_v5upgrade	\
			teamspeak2 threshold unixsock uuid write_graphite

.for option in ${DEFAULT_PLUGINS}
CONFIGURE_ARGS+=	--enable-${option}
.endfor

# Several libs not generated in time for linking collectd
MAKE_JOBS_SAFE=		no

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/collectd

.include "options.mk"

CONF_FILES+=		share/examples/collectd/collectd.conf 		\
			${PKG_SYSCONFDIR}/collectd.conf

BUILD_DEFS+=		VARBASE

OWN_DIRS+=		${VARBASE}/db/collectd

COLLECTD_USER?=			collectd
COLLECTD_GROUP?=		${COLLECTD_USER}
PKG_USERS_VARS+=		COLLECTD_USER
PKG_GROUPS_VARS+=		COLLECTD_GROUP
PKG_GROUPS=			${COLLECTD_GROUP}
PKG_USERS=			${COLLECTD_USER}:${COLLECTD_GROUP}
PKG_GECOS.${COLLECTD_USER}=	collectd unprivileged user

.include "../../mk/bsd.pkg.mk"
