# $NetBSD: Makefile,v 1.2 1998/05/30 14:41:16 frueauf Exp $
# FreeBSD Id: Makefile,v 1.18 1998/04/06 20:50:31 andreas Exp
#

DISTNAME=	ucd-snmp
PKGNAME=	ucd-snmp-3.4
WRKSRC=		${WRKDIR}/ucd-snmp-3.4
CATEGORIES=	net
MASTER_SITES= 	ftp://ftp.ece.ucdavis.edu/pub/snmp/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.or.jp/pub/network/snmp/ucd-snmp/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-defaults

MAN1=		snmpbulkwalk.1 snmpd.1 snmpdelta.1 snmpget.1 snmpgetnext.1 \
		snmpnetstat.1 snmpset.1 snmpstatus.1 snmptable.1 snmptest.1 \
		snmptranslate.1 snmptrap.1 snmpwalk.1
MAN3=		mib_api.3 snmp_api.3
MAN5=		snmpd.conf.5 variables.5
MAN8=		snmptrapd.8
BIN=		snmpbulkwalk snmpget snmpgetnext snmpnetstat snmpset \
		snmpstatus snmptest snmptranslate snmptrap snmpwalk
SBIN=		snmpd snmptrapd

post-install:
	( cd ${PREFIX}/bin; strip ${BIN} )
	( cd ${PREFIX}/sbin; strip ${SBIN} )
	@${MKDIR} ${PREFIX}/share/examples/ucd-snmp
	@for F in ${WRKSRC}/etc/* ; do \
		${INSTALL_DATA} $$F ${PREFIX}/share/examples/ucd-snmp ; done
	@if [ ! -f ${PREFIX}/etc/rc.d/snmpd.sh ]; then \
		${ECHO} "Creating ${PREFIX}/etc/rc.d/snmpd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/snmpd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/snmpd ] && ${PREFIX}/sbin/snmpd && ${ECHO} -n ' snmpd'" >> ${PREFIX}/etc/rc.d/snmpd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/snmpd.sh; \
	 fi

.include "../../mk/bsd.pkg.mk"
