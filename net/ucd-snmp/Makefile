# $NetBSD: Makefile,v 1.11 1999/04/21 20:47:22 abs Exp $
# FreeBSD Id: Makefile,v 1.18 1998/04/06 20:50:31 andreas Exp
#

DISTNAME=	ucd-snmp-3.6.1
CATEGORIES=	net
MASTER_SITES= 	ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ece.ucdavis.edu/ucd-snmp/

BUILD_DEPENDS+=	autoconf:../../devel/autoconf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-defaults
CONFIGURE_ARGS+= --with-libwrap
# note the default appends a redundant and silly ".log"
CONFIGURE_ARGS+= --with-logfile="/var/log/snmpd"
# this might make it easier to use scotty's mibs, and local ones too
CONFIGURE_ARGS+= --with-mibdirs="${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tnm2.1.8/mibs:/usr/local/share/snmp/mibs"

# pass down PKG_PREFIX to simulate pkg_add's environment
MAKE_ENV+=	PKG_PREFIX="${PREFIX}"

.include "../../mk/bsd.prefs.mk"

pre-configure:
	(cd ${WRKSRC}; autoreconf --force)

# Need to run INSTALL script as this doesn't happen automagically from pkgsrc.
post-install:
	@${MKDIR} ${PREFIX}/share/examples/ucd-snmp
	@for F in ${WRKSRC}/etc/* ; do \
		${INSTALL_DATA} $$F ${PREFIX}/share/examples/ucd-snmp ; \
	done
	${ECHO} "Creating ${PREFIX}/etc/rc.d/snmpd.sh startup file."; \
	${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/snmpd.sh; \
	${ECHO} "[ -x ${PREFIX}/sbin/snmpd ] && ${PREFIX}/sbin/snmpd && ${ECHO} -n ' snmpd'" >> ${PREFIX}/etc/rc.d/snmpd.sh
	${CHMOD} 755 ${PREFIX}/etc/rc.d/snmpd.sh
	${INSTALL_DATA_DIR} ${PREFIX}/lib/snmp/dlmod
	${TOUCH} ${PREFIX}/lib/snmp/dlmod/.keepme

.include "../../mk/bsd.pkg.mk"
