# $NetBSD: Makefile,v 1.23 2000/11/05 11:07:57 veego Exp $
# FreeBSD Id: Makefile,v 1.18 1998/04/06 20:50:31 andreas Exp
#

DISTNAME=	ucd-snmp-4.1.2
CATEGORIES=	net
MASTER_SITES= 	ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.or.jp/pub/network/snmp/ucd-snmp/

#PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
#PATCHFILES=	ucd-snmp-4.0.1-v6-20000124b.diff.gz
#PATCH_DIST_STRIP=	-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://ucd-snmp.ucdavis.edu/

BUILD_DEPENDS+=	autoreconf:../../devel/autoconf

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

USE_LIBTOOL=	yes
USE_SSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-defaults --with-libwrap --with-logfile="/var/log/snmpd"
CONFIGURE_ARGS+=--enable-shared
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

# this might make it easier to use scotty's mibs, and local ones too
CONFIGURE_ARGS+=--with-mibdirs="${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tcl/tnm2.1.10/mibs:/usr/local/share/snmp/mibs"

# deal with libwrap bogosity by providing these variables to programs which
# do not supply them:
post-extract:
	@${ECHO} 'int allow_severity, deny_severity;' >${WRKSRC}/snmplib/libwrap.c

pre-configure:
	@(cd ${WRKSRC} && autoreconf)

post-build:
	@${SED} -e 's,@PREFIX@,${PREFIX},' \
	    < ${FILESDIR}/snmpd.sh > ${WRKDIR}/snmpd.sh

post-install:
	@${MKDIR} ${PREFIX}/share/examples/ucd-snmp
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.conf ${PREFIX}/share/examples/ucd-snmp
	${INSTALL_DATA_DIR} ${PREFIX}/lib/snmp/dlmod
	${INSTALL_SCRIPT} ${WRKDIR}/snmpd.sh ${PREFIX}/etc/rc.d

.if (${OPSYS} == "NetBSD")
CFLAGS+=	-Dnetbsd1
.endif

.include "../../mk/bsd.pkg.mk"
