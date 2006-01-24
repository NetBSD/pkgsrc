# $NetBSD: Makefile,v 1.8 2006/01/24 07:32:30 wiz Exp $
#

DISTNAME=		netdisco-0.94_with_mibs
PKGNAME=		netdisco-0.94
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=netdisco/}

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.netdisco.org/
COMMENT=		Open Source web-based network management tool

DEPENDS+=		p5-SNMP-Info-*:../../net/p5-SNMP-Info
DEPENDS+=		p5-Apache-DBI-*:../../databases/p5-Apache-DBI
DEPENDS+=		p5-Apache-Session-*:../../www/p5-Apache-Session
DEPENDS+=		p5-DBD-postgresql-*:../../databases/p5-DBD-postgresql
DEPENDS+=		p5-DB_File-*:../../databases/p5-DB_File
DEPENDS+=		p5-MasonX-Request-WithApacheSession-*:../../www/p5-MasonX-Request-WithApacheSession
DEPENDS+=		p5-HTML-Parser-*:../../www/p5-HTML-Parser
DEPENDS+=		p5-GraphViz-*:../../graphics/p5-GraphViz
DEPENDS+=		p5-Compress-Zlib-*:../../devel/p5-Compress-Zlib

#DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
#MESSAGE_SRC=		${.CURDIR}/MESSAGE

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/${PKGNAME_NOREV}

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/doc_munge
REPLACE_PERL+=  bin/test_cdp.pl
REPLACE_PERL+=  bin/test_fwtable.pl
REPLACE_PERL+=  bin/test_iproute.pl
REPLACE_PERL+=  bin/parse_kismet_ap
REPLACE_PERL+=  netdisco
REPLACE_PERL+=  mibs/chk_dups
REPLACE_PERL+=  mibs/rm_cisco_dups
REPLACE_PERL+=  mibs/chk_mibs
REPLACE_PERL+=  mibs/snmpwalkmib

SUBST_CLASSES+=			installdir path var
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
SUBST_MESSAGE.installdir=	"Fixing hardcoded install directory path."

SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	bin/catalyst_mac_vlan.pl bin/port_control
SUBST_FILES.path+=	bin/test_cache.pl bin/test_dev.pl bin/test_stats.pl
SUBST_FILES.path+=	bin/parse_mac
SUBST_FILES.path+=	doc/INSTALL.html doc/INSTALL.pod html/doc/INSTALL.html
SUBST_FILES.path+=	INSTALL netdisco.crontab
SUBST_SED.path=		-e "s|/usr/local/bin|${PREFIX}/bin|g"
SUBST_MESSAGE.path=	"Fixing hardcoded path."

SUBST_STAGE.var=	pre-configure
SUBST_FILES.var=	netdisco.conf
SUBST_SED.var=		-e "s|@VARBASE@|${VARBASE}|g"
SUBST_MESSAGE.var=	"Fixing data directory."

NETDISCOUSER?=	netdisco
NETDISCOGROUP?=	netdisco
BUILD_DEFS+=	NETDISCOUSER NETDISCOGROUP

PKG_USERS=	${NETDISCOUSER}:${NETDISCOGROUP}::Netdisco\ administrator:${PREFIX}/netdisco:${SH}
PKG_GROUPS=	${NETDISCOGROUP}

PKG_SYSCONFVAR=		netdisco
PKG_SYSCONFDIR.netdisco= ${PREFIX}/netdisco
EGDIR=			${PREFIX}/share/examples/netdisco
CONF_FILES=		${EGDIR}/netdisco.conf ${PKG_SYSCONFDIR}/netdisco.conf
CONF_FILES_PERMS+=	${EGDIR}/netdisco.conf ${PKG_SYSCONFDIR}/netdisco.conf \
			${NETDISCOUSER} ${NETDISCOGROUP} 0660
CONF_FILES+=		${EGDIR}/netdisco-topology.txt ${PKG_SYSCONFDIR}/netdisco-topology.txt

REQD_DIRS=              ${PREFIX}/netdisco ${EGDIR}
OWN_DIRS_PERMS+=        ${VARBASE}/netdisco ${NETDISCOUSER} ${NETDISCOGROUP} 0775
RCD_SCRIPTS=		netdisco

.include "../../mk/apache.mk"

do-build:
	${RM} -f ${WRKSRC}/html/doc/ChangeLog.txt
	${RM} -f ${WRKSRC}/Makefile
	for i in INSTALL README README-API-BACKEND README-API-SHARED \
	    UPGRADE ChangeLog; do \
		${RM} -f ${WRKSRC}/doc/$$i ;\
		${MV} ${WRKSRC}/$$i ${WRKSRC}/doc/ ;\
	done
	cd ${WRKSRC};
	${FIND} . \( -name '*.orig' -o -name '*.bak' \) -exec ${RM} -f {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/netdisco_daemon \
	    ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}/netdisco
	${RM} -f ${WRKSRC}/bin/netdisco_daemon
	cd ${WRKSRC} && ${PAX} -rw -pp . ${PREFIX}/netdisco
	${CHOWN} -R ${NETDISCOUSER}:${NETDISCOGROUP} ${PREFIX}/netdisco
	${CHMOD} 775 ${PREFIX}/netdisco/html
	for i in netdisco.conf netdisco-topology.txt netdisco.crontab \
	    netdisco_apache.conf netdisco_apache_dir.conf; do \
		${MV} ${PREFIX}/netdisco/$$i ${EGDIR}/ ;\
	done
	${CHGRP} -R ${APACHE_GROUP} ${PREFIX}/netdisco/mason
	${CHMOD} -R 775 ${PREFIX}/netdisco/mason

.include "../../mk/bsd.pkg.mk"
