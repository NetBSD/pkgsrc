# $NetBSD: Makefile,v 1.16 2006/11/10 17:42:48 tv Exp $
#

DISTNAME=		netdisco-0.94_with_mibs
PKGNAME=		netdisco-0.94
PKGREVISION=		5
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netdisco/}

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.netdisco.org/
COMMENT=		Open Source web-based network management tool

DEPENDS+=		p5-SNMP-Info-[0-9]*:../../net/p5-SNMP-Info
DEPENDS+=		p5-Apache-DBI-[0-9]*:../../databases/p5-Apache-DBI
DEPENDS+=		p5-Apache-Session-[0-9]*:../../www/p5-Apache-Session
DEPENDS+=		p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=		p5-DB_File-[0-9]*:../../databases/p5-DB_File
DEPENDS+=		p5-MasonX-Request-WithApacheSession-[0-9]*:../../www/p5-MasonX-Request-WithApacheSession
DEPENDS+=		p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=		p5-Graph-[0-9]*:../../devel/p5-Graph
DEPENDS+=		p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz
DEPENDS+=		p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/${PKGNAME_NOREV}

USE_TOOLS+=	perl:run
REPLACE_PERL+=	bin/doc_munge
REPLACE_PERL+=	bin/test_cdp.pl
REPLACE_PERL+=	bin/test_fwtable.pl
REPLACE_PERL+=	bin/test_iproute.pl
REPLACE_PERL+=	bin/parse_kismet_ap
REPLACE_PERL+=	netdisco
REPLACE_PERL+=	mibs/chk_dups
REPLACE_PERL+=	mibs/rm_cisco_dups
REPLACE_PERL+=	mibs/chk_mibs
REPLACE_PERL+=	mibs/snmpwalkmib

SUBST_CLASSES+=			installdir path var apachevers
SUBST_STAGE.installdir=		pre-configure
SUBST_FILES.installdir=		sql/pg_run sql/pg_init sql/pg_back
SUBST_FILES.installdir+=	bin/netdisco_daemon
SUBST_FILES.installdir+=	netdisco
SUBST_FILES.installdir+=	netdisco.conf netdisco.crontab
SUBST_FILES.installdir+=	netdisco_apache.conf netdisco_apache_dir.conf
SUBST_FILES.installdir+=	bin/test_cache.pl bin/test_cdp.pl
SUBST_FILES.installdir+=	bin/test_dev.pl bin/test_stats.pl
SUBST_FILES.installdir+=	bin/debian_install.sh
SUBST_FILES.installdir+=	bin/test_fwtable.pl bin/test_iproute.pl
SUBST_FILES.installdir+=	doc/INSTALL.html doc/INSTALL.pod
SUBST_FILES.installdir+=	doc/README.pod doc/README.html
SUBST_FILES.installdir+=	doc/UPGRADE.html doc/UPGRADE.pod
SUBST_FILES.installdir+=	INSTALL README UPGRADE
SUBST_FILES.installdir+=	html/doc/INSTALL.html html/doc/README.html
SUBST_FILES.installdir+=	html/doc/UPGRADE.html html/admin_reconfig.html
SUBST_FILES.installdir+=	netdisco.crontab
SUBST_FILES.installdir+=	mibs/snmp.conf
SUBST_SED.installdir=		-e "s|/usr/local/netdisco|${PREFIX}/netdisco|g"
SUBST_MESSAGE.installdir=	Fixing hardcoded install directory path.

SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	bin/catalyst_mac_vlan.pl bin/port_control
SUBST_FILES.path+=	bin/test_cache.pl bin/test_dev.pl bin/test_stats.pl
SUBST_FILES.path+=	bin/parse_mac
SUBST_FILES.path+=	doc/INSTALL.html doc/INSTALL.pod html/doc/INSTALL.html
SUBST_FILES.path+=	INSTALL netdisco.crontab
SUBST_SED.path=		-e "s|/usr/local/bin|${PREFIX}/bin|g"
SUBST_MESSAGE.path=	Fixing hardcoded path.

SUBST_STAGE.var=	pre-configure
SUBST_FILES.var=	netdisco.conf
SUBST_SED.var=		-e "s|@VARBASE@|${VARBASE}|g"
SUBST_MESSAGE.var=	Fixing data directory.

NETDISCOUSER?=	netdisco
NETDISCOGROUP?=	netdisco
BUILD_DEFS+=	NETDISCOUSER NETDISCOGROUP

PKG_GROUPS=	${NETDISCOGROUP}
PKG_USERS=	${NETDISCOUSER:Q}:${NETDISCOGROUP:Q}

PKG_GECOS.${NETDISCOUSER}=	Netdisco administrator
PKG_HOME.${NETDISCOUSER}=	${PREFIX}/netdisco
PKG_SHELL.${NETDISCOUSER}=	${SH}

PKG_SYSCONFVAR=		netdisco
PKG_SYSCONFDIR.netdisco=	${PREFIX}/netdisco
EGDIR=			${PREFIX}/share/examples/netdisco
CONF_FILES=		${EGDIR:Q}/netdisco.conf ${PKG_SYSCONFDIR:Q}/netdisco.conf
CONF_FILES_PERMS+=	${EGDIR:Q}/netdisco.conf ${PKG_SYSCONFDIR:Q}/netdisco.conf \
			${NETDISCOUSER} ${NETDISCOGROUP} 0660
CONF_FILES+=		${EGDIR:Q}/netdisco-topology.txt ${PKG_SYSCONFDIR:Q}/netdisco-topology.txt

REQD_DIRS+=		${PREFIX:Q}/netdisco ${EGDIR:Q}
OWN_DIRS_PERMS+=	${VARBASE:Q}/netdisco ${NETDISCOUSER} ${NETDISCOGROUP} 0775
RCD_SCRIPTS=		netdisco

.include "../../mk/apache.mk"

.if ${PKG_APACHE} == "apache13"
SUBST_STAGE.apachevers=	pre-configure
SUBST_FILES.var=	netdisco_apache.conf
SUBST_SED.var=		-e "s|@APACHE2@|\#uncomment for apache2|g"
SUBST_MESSAGE.var=	Fixing config files for apache-1.3
.elif ${PKG_APACHE} == "apache2"
SUBST_STAGE.apachevers=	pre-configure
SUBST_FILES.var=	netdisco_apache.conf
SUBST_SED.var=		-e "s|@APACHE2@||g"
SUBST_MESSAGE.var=	Fixing config files for apache-2
.endif

do-build:
	${RM} -f ${WRKSRC:Q}/html/doc/ChangeLog.txt
	${RM} -f ${WRKSRC:Q}/Makefile
	set -e; \
	for i in INSTALL README README-API-BACKEND README-API-SHARED \
	    UPGRADE ChangeLog; do \
		${RM} -f ${WRKSRC:Q}/doc/"$$i"; \
		${MV} ${WRKSRC:Q}/"$$i" ${WRKSRC:Q}/doc/; \
	done
	cd ${WRKSRC:Q} && \
	${FIND} . \( -name '*.orig' -o -name '*.bak' \) -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/bin/netdisco_daemon \
	    ${PREFIX:Q}/${RCD_SCRIPTS_EXAMPLEDIR:Q}/netdisco
	${RM} -f ${WRKSRC:Q}/bin/netdisco_daemon
	cd ${WRKSRC:Q} && ${PAX} -rw -pp . ${PREFIX:Q}/netdisco
	${CHOWN} -R ${NETDISCOUSER}:${NETDISCOGROUP} ${PREFIX:Q}/netdisco
	${CHMOD} 775 ${PREFIX:Q}/netdisco/html
	set -e; \
	for i in netdisco.conf netdisco-topology.txt netdisco.crontab \
	    netdisco_apache.conf netdisco_apache_dir.conf; do \
		${MV} ${PREFIX:Q}/netdisco/"$$i" ${EGDIR:Q}/ ;\
	done
	${CHGRP} -R ${APACHE_GROUP} ${PREFIX:Q}/netdisco/mason
	${CHMOD} -R 775 ${PREFIX:Q}/netdisco/mason

.include "../../mk/bsd.pkg.mk"
