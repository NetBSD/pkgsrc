# $NetBSD: Makefile,v 1.50 2022/06/28 11:35:04 wiz Exp $

DISTNAME=		netdisco-1.3.3_with_mibs
PKGNAME=		${DISTNAME:S/_with_mibs//}
PKGREVISION=		7
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netdisco/}
SITES.oui.txt=		http://standards.ieee.org/regauth/oui/
DISTFILES=		${DEFAULT_DISTFILES} oui.txt

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.netdisco.org/
COMMENT=		Open Source web-based network management tool
LICENSE=		modified-bsd

DEPENDS+=		p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=		p5-SNMP-Info>=2.04:../../net/p5-SNMP-Info
DEPENDS+=		p5-Apache-DBI-[0-9]*:../../databases/p5-Apache-DBI
DEPENDS+=		p5-Apache-Session-[0-9]*:../../www/p5-Apache-Session
DEPENDS+=		p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
#DEPENDS+=		{perl>=5,p5-DB_File-[0-9]*}:../../databases/p5-DB_File
DEPENDS+=		p5-MasonX-Request-WithApacheSession-[0-9]*:../../www/p5-MasonX-Request-WithApacheSession
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=		p5-Graph-[0-9]*:../../devel/p5-Graph
DEPENDS+=		p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz
#DEPENDS+=		{perl>=5.9.3,p5-IO-Compress-[0-9]*}:../../devel/p5-IO-Compress	# Compress::Zlib
DEPENDS+=		p5-Net-NBName-[0-9]*:../../net/p5-Net-NBName
DEPENDS+=		p5-${APACHE_PKG_PREFIX}-libapreq2-[0-9]*:../../www/p5-libapreq2
DEPENDS+=		p5-Parallel-ForkManager-[0-9]*:../../devel/p5-Parallel-ForkManager

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	${EGDIR} ${PKGBASE}

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	pax perl:run
REPLACE_PERL+=	bin/device_to_csv
REPLACE_PERL+=	bin/doc_munge
REPLACE_PERL+=	bin/firewall_arp
REPLACE_PERL+=	bin/parse_kismet_ap
REPLACE_PERL+=	bin/pod_arg_link_fix
REPLACE_PERL+=	bin/search_node.pl
REPLACE_PERL+=	bin/test_cdp.pl
REPLACE_PERL+=	bin/test_fwtable.pl
REPLACE_PERL+=	bin/test_iproute.pl
REPLACE_PERL+=	bin/snmpv3_key
REPLACE_PERL+=	netdisco
REPLACE_PERL+=	mibs/chk_dups
REPLACE_PERL+=	mibs/diff_dir
REPLACE_PERL+=	mibs/rm_cisco_dups
REPLACE_PERL+=	mibs/chk_mibs
REPLACE_PERL+=	mibs/snmpwalkmib
REPLACE_PERL+=	mibs/split-extreme
REPLACE_PERL+=	sql/pg

SUBST_CLASSES+=			installdir path varbase apachevers
SUBST_STAGE.installdir=		pre-configure
SUBST_FILES.installdir=		sql/pg
SUBST_FILES.installdir+=	bin/netdisco_daemon
SUBST_FILES.installdir+=	netdisco
SUBST_FILES.installdir+=	netdisco.conf netdisco.crontab
SUBST_FILES.installdir+=	netdisco_apache.conf netdisco_apache_dir.conf
SUBST_FILES.installdir+=	bin/test_cache.pl bin/test_cdp.pl
SUBST_FILES.installdir+=	bin/test_dev.pl bin/test_stats.pl
SUBST_FILES.installdir+=	bin/debian_install.sh
SUBST_FILES.installdir+=	bin/test_fwtable.pl bin/test_iproute.pl
SUBST_FILES.installdir+=	doc/INSTALL.pod
SUBST_FILES.installdir+=	doc/README.pod
SUBST_FILES.installdir+=	doc/UPGRADE.pod
SUBST_FILES.installdir+=	INSTALL README UPGRADE
SUBST_FILES.installdir+=	html/admin_reconfig.html
SUBST_FILES.installdir+=	mibs/snmp.conf
SUBST_SED.installdir=		-e "s|/usr/local/netdisco|${PREFIX}/netdisco|g"
SUBST_MESSAGE.installdir=	Fixing hardcoded install directory path.

SUBST_STAGE.path=		pre-configure
SUBST_FILES.path=		bin/catalyst_mac_vlan.pl bin/port_control
SUBST_FILES.path+=		bin/test_cache.pl bin/test_dev.pl bin/test_stats.pl
SUBST_FILES.path+=		bin/parse_mac
SUBST_FILES.path+=		doc/INSTALL.pod
SUBST_FILES.path+=		INSTALL netdisco.crontab
SUBST_SED.path=			-e "s|/usr/local/bin|${PREFIX}/bin|g"
SUBST_MESSAGE.path=		Fixing hardcoded path.

SUBST_STAGE.varbase=		pre-configure
SUBST_FILES.varbase=		netdisco.conf
SUBST_VARS.varbase=		VARBASE
SUBST_MESSAGE.varbase=		Fixing data directory.

NETDISCOUSER?=			netdisco
NETDISCOGROUP?=			netdisco

PKG_GROUPS_VARS+=		NETDISCOGROUP
PKG_USERS_VARS+=		NETDISCOUSER

PKG_GROUPS=			${NETDISCOGROUP}
PKG_USERS=			${NETDISCOUSER:Q}:${NETDISCOGROUP:Q}

PKG_GECOS.${NETDISCOUSER}=	Netdisco administrator
PKG_HOME.${NETDISCOUSER}=	${PREFIX}/netdisco
PKG_SHELL.${NETDISCOUSER}=	${SH}

PKG_SYSCONFVAR=			netdisco
PKG_SYSCONFDIR.netdisco=	${PREFIX}/netdisco

EGDIR=			${PREFIX}/share/examples/netdisco
CONF_FILES=		${EGDIR:Q}/netdisco.conf ${PKG_SYSCONFDIR:Q}/netdisco.conf
CONF_FILES_PERMS+=	${EGDIR:Q}/netdisco.conf ${PKG_SYSCONFDIR:Q}/netdisco.conf \
			${NETDISCOUSER} ${NETDISCOGROUP} 0660
CONF_FILES+=		${EGDIR:Q}/netdisco-topology.txt ${PKG_SYSCONFDIR:Q}/netdisco-topology.txt

REQD_DIRS+=		${PREFIX:Q}/netdisco ${EGDIR:Q}
OWN_DIRS_PERMS+=	${VARBASE:Q}/netdisco ${NETDISCOUSER} ${NETDISCOGROUP} 0775
OWN_DIRS_PERMS+=	${PREFIX:Q}/netdisco/html ${NETDISCOUSER} ${NETDISCOGROUP} 0775
OWN_DIRS_PERMS+=	${PREFIX:Q}/netdisco/mason ${NETDISCOUSER} ${APACHE_GROUP} 0775

RCD_SCRIPTS=			netdisco
RCD_SCRIPT_SRC.netdisco=	${WRKSRC:Q}/bin/netdisco_daemon

.include "../../mk/apache.mk"

SUBST_STAGE.apachevers=		pre-configure
SUBST_FILES.apachevers=		html/admin_user.html html/change_pw.html html/login.html
SUBST_FILES.apachevers+=	html/logout.html html/portcontrol.html
SUBST_FILES.apachevers+=	html/public_debugging.html
SUBST_SED.apachevers=		-e "s|connection->remote_ip|connection->client_ip|g"
SUBST_MESSAGE.apachevers=	Fixing perl files for apache > 2.2.

do-build:
	${RM} -f ${WRKSRC:Q}/html/doc/ChangeLog.txt
	${RM} -f ${WRKSRC:Q}/Makefile
	${RM} -f ${WRKSRC:Q}/bin/debian_install.sh
	set -e; \
	for i in INSTALL README README-API-BACKEND README-API-SHARED \
	    UPGRADE ChangeLog; do \
		${RM} -f ${WRKSRC:Q}/doc/"$$i"; \
		${MV} ${WRKSRC:Q}/"$$i" ${WRKSRC:Q}/doc/; \
	done
	cd ${WRKSRC:Q} && \
	${FIND} . \( -name '*.orig' -o -name '*.bak' \) -print | ${XARGS} ${RM} -f
	${CP} ${DISTDIR}/oui.txt ${WRKSRC:Q}

do-install:
	${RM} -f ${WRKSRC:Q}/bin/netdisco_daemon
	cd ${WRKSRC:Q} && pax -rw -pp . ${DESTDIR}${PREFIX:Q}/netdisco
	set -e; \
	for i in netdisco.conf netdisco-topology.txt netdisco.crontab \
	    netdisco_apache.conf netdisco_apache_dir.conf; do \
		${MV} ${DESTDIR}${PREFIX:Q}/netdisco/"$$i" ${DESTDIR}${EGDIR:Q}/ ;\
	done

.include "../../mk/bsd.pkg.mk"
