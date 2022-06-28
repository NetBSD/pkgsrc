# $NetBSD: Makefile,v 1.31 2022/06/28 11:35:54 wiz Exp $

PKGREVISION= 2
.include "../../sysutils/collectd/Makefile.common"

COMMENT=	Statistics collection daemon base

RCD_SCRIPTS=	collectd

.include "../../mk/bsd.prefs.mk"

# Simple plugins that have no dependencies
DEFAULT_PLUGINS=	aggregation apcups check_uptime chrony csv	\
			email exec filecount hddtemp logfile logparser	\
			match_empty_counter match_hashed match_regex	\
			match_timediff match_value mbmon memcached	\
			notify_nagios ntpd olsrd openvpn powerdns	\
			statsd table tail tail_csv target_notification	\
			target_replace target_scale target_set		\
			target_v5upgrade teamspeak2 threshold unixsock	\
			uuid write_graphite write_influxdb_udp write_log\
			write_sensu write_syslog write_tsdb zookeeper

.for option in ${DEFAULT_PLUGINS}
CONFIGURE_ARGS+=	--enable-${option}
.endfor

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/collectd

PKGCONFIG_OVERRIDE=	src/libcollectdclient/libcollectdclient.pc.in

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
