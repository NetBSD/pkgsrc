# $NetBSD: Makefile,v 1.36 2001/09/24 09:40:00 tron Exp $

DISTNAME=	ucd-snmp-4.1.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=net-snmp/} \
		ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.or.jp/pub/network/snmp/ucd-snmp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://net-snmp.sourceforge.net/
COMMENT=	Extensible SNMP implementation

BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

USE_LIBTOOL=	yes
USE_SSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-defaults --with-libwrap --with-logfile="/var/log/snmpd"
CONFIGURE_ARGS+=--with-mib-modules="smux host"
# NOTE: if you do not allow dummy values some tools such as
# scotty/tkined may ignore results when they shouldn't.
CONFIGURE_ARGS+=--with-dummy-values
# NOTE: without this the default is USER@DOMAINNAME of the package builder
CONFIGURE_ARGS+=--with-sys-contact="default_user@contact.domain"
CONFIGURE_ARGS+=--with-sys-location="defaultlocation"
CONFIGURE_ARGS+=--enable-shared
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

# this might make it easier to use scotty's mibs, and local ones too
CONFIGURE_ARGS+=--with-mibdirs="${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tcl/tnm2.1.10/mibs:${PREFIX}/lib/tnm2.1.8/mibs:/usr/local/share/snmp/mibs"

# deal with libwrap bogosity by providing these variables to programs which
# do not supply them:
post-extract:
	@${ECHO} 'int allow_severity, deny_severity;' >${WRKSRC}/snmplib/libwrap.c
	${LN} ${WRKSRC}/s/netbsd.h ${WRKSRC}/s/netbsdelf.h

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

post-build:
	${SED} 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/snmpd.sh > ${WRKDIR}/snmpd
	${SED} 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/snmptrapd.sh > ${WRKDIR}/snmptrapd

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ucd-snmp
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.conf ${PREFIX}/share/examples/ucd-snmp
	${INSTALL_DATA_DIR} ${PREFIX}/lib/snmp/dlmod
	${INSTALL_SCRIPT} ${WRKDIR}/snmpd ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKDIR}/snmptrapd ${PREFIX}/etc/rc.d

.if (${OPSYS} == "NetBSD")
CFLAGS+=	-Dnetbsd1
.endif

.include "../../mk/bsd.pkg.mk"
