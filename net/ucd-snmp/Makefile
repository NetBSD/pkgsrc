# $NetBSD: Makefile,v 1.7 1998/10/07 20:17:20 agc Exp $
# FreeBSD Id: Makefile,v 1.18 1998/04/06 20:50:31 andreas Exp
#

DISTNAME=	ucd-snmp-3.5.3
CATEGORIES=	net
MASTER_SITES= 	ftp://ftp.ece.ucdavis.edu/pub/snmp/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.or.jp/pub/network/snmp/ucd-snmp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ece.ucdavis.edu/ucd-snmp/

CONFLICTS=	ucd-snmp-3.4 ucd-snmp-3.5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-defaults

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
