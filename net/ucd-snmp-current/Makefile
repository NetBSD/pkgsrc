# $NetBSD: Makefile,v 1.3 2000/03/17 19:28:37 kim Exp $
#

DISTNAME=	ucd-snmp-4.0.1
PKGNAME=	${DISTNAME}.12
CATEGORIES=	net
MASTER_SITES= 	ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/

# This patch is malformed (first Index line is missing, other
# Index lines are relative to the agent directory), so I've
# put a fixed copy in ${FILESDIR}.  (kim 1999-09-21)

#PATCH_SITES=	http://ucd-snmp.ucdavis.edu/patches/
#PATCHFILES=	012.patch
#DIST_SUBDIR=	ucd-snmp

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ece.ucdavis.edu/ucd-snmp/

BUILD_DEPENDS+=	autoconf:../../devel/autoconf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-defaults
CONFIGURE_ARGS+= --with-dummy-values
CONFIGURE_ARGS+= --with-libwrap
CONFIGURE_ARGS+= --with-sys-contact=root
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
