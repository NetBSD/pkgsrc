# $NetBSD: Makefile,v 1.19 2004/04/22 16:50:02 christos Exp $

DISTNAME=	net-snmp-5.0.9
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=net-snmp/} \
		ftp://ftp.net-smnp.org/pub/sourceforge/net-snmp/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.net-snmp.org/
COMMENT=	Extensible SNMP implementation

CONFLICTS=	ucd-snmp-[0-9]*

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

NET_SNMP_SYS_CONTACT?=		default_user@contact.domain
NET_SNMP_SYS_LOCATION?=		defaultlocation
NET_SNMP_PERSISTENTDIR?=	/var/net-snmp
NET_SNMP_MIBDIRS?=		\$$HOME/.snmp/mibs:${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tcl/tnm2.1.10/mibs:/usr/local/share/snmp/mibs

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

.if ${OPSYS} == "NetBSD" && empty(CFLAGS:U:M*-Dnetbsd1*)
CFLAGS+=		-Dnetbsd1
.endif

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared
# net-snmp doesn't do IPv6 on Solaris
.if (defined(USE_INET6) && (${USE_INET6} == "YES")) && ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=	--enable-ipv6
PLIST_SUBST+=   	IPV6H=
.else
CONFIGURE_ARGS+=	--disable-ipv6
PLIST_SUBST+=   	IPV6H="@comment "
.endif
CONFIGURE_ARGS+=	--with-defaults

.include "../../security/tcp_wrappers/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libwrap

.if defined(NET_SNMP_USE_SSL) && ${NET_SNMP_USE_SSL} == "YES"
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
.endif

CONFIGURE_ARGS+=	--with-sys-contact="${NET_SNMP_SYS_CONTACT}"
CONFIGURE_ARGS+=	--with-sys-location="${NET_SNMP_SYS_LOCATION}"
#
# NOTE:  if you specify a logfile then this file will be written to by
# default and although it can be disabled on the command line, the
# daemon must be stopped to cycle it properly.  Remember rc.d/snmpd
# will use '-s' to enable standard syslog logging anyway.
#
CONFIGURE_ARGS+=	--with-logfile=none
CONFIGURE_ARGS+=	--with-persistent-directory="${NET_SNMP_PERSISTENTDIR}"
.if !empty(NET_SNMP_MIBDIRS)
CONFIGURE_ARGS+=	--with-mibdirs="${NET_SNMP_MIBDIRS}"
.endif
CONFIGURE_ARGS+=	--with-mib-modules="smux host"
#
# Using "dummy" values is technically not compliant with SNMP specs, but
# otherwise, some tools, e.g. net/tcl-scotty, net/tkined, may ignore results
# when they shouldn't.
#
CONFIGURE_ARGS+=	--with-dummy-values
#
# Install the UCD-SNMP look-alike headers and libraries to ease porting of
# older software to use net-snmp.
#
CONFIGURE_ARGS+=	--enable-ucd-snmp-compatibility

.if (${OPSYS} == "NetBSD") || !exists(/usr/bin/lpstat)
CONFIGURE_ENV+=		ac_cv_path_LPSTAT_PATH=no
.endif
CONFIGURE_ENV+=		PERLPROG="${PERL5}"

.if (${OPSYS} == "NetBSD")
OSVERSION_SPECIFIC=	YES
.endif

# Handle ${PREFIX}/share/snmp in the DEINSTALL script since it may contain
# leftover config files or pidfiles after deinstallation.
#
OWN_DIRS=	${PREFIX}/share/snmp
RCD_SCRIPTS=	snmpd snmptrapd

.include "../../lang/perl5/buildlink3.mk"

post-buildlink:
.if !empty(MACHINE_PLATFORM:MNetBSD-1.5.[123]*-i386)
	${MKDIR} ${BUILDLINK_DIR}/include/sys
	${CP} ${FILESDIR}/disklabel.h ${BUILDLINK_DIR}/include/sys
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/net-snmp
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.conf				\
		${PREFIX}/share/examples/net-snmp/EXAMPLE.conf

.include "../../mk/bsd.pkg.mk"
