# $NetBSD: Makefile,v 1.52 2006/09/14 15:48:27 ghen Exp $

DISTNAME=	net-snmp-5.3.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=net-snmp/} \
		ftp://ftp.net-smnp.org/pub/sourceforge/net-snmp/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.net-snmp.org/
COMMENT=	Extensible SNMP implementation

CONFLICTS=	ucd-snmp-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

MAKE_ENV+=	OPSYS=${OPSYS:Q}

# The self-test of Perl modules only works after installation because perl
# can't load the shared libraries from WRKSRC/
# Until this is fixed you can test them after installation by doing
# `make test TEST_TARGET=perltest'
TEST_TARGET?=		test

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
OSVERSION_SPECIFIC=	YES
.  if empty(CFLAGS:U:M*-Dnetbsd1*)
CFLAGS+=		-Dnetbsd1
.  endif
.endif

.if (${OPSYS} == "NetBSD") || !exists(/usr/bin/lpstat)
CONFIGURE_ENV+=		ac_cv_path_LPSTAT_PATH=no
.endif

NET_SNMP_SYS_CONTACT?=		default_user@contact.domain
NET_SNMP_SYS_LOCATION?=		defaultlocation
NET_SNMP_PERSISTENTDIR?=	${VARBASE}/net-snmp
NET_SNMP_MIBDIRS?=		\$$HOME/.snmp/mibs:${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tcl/tnm2.1.10/mibs:/usr/local/share/snmp/mibs

BUILD_DEFS+=		NET_SNMP_SYS_CONTACT
BUILD_DEFS+=		NET_SNMP_SYS_LOCATION
BUILD_DEFS+=		NET_SNMP_PERSISTENTDIR
BUILD_DEFS+=		NET_SNMP_MIBDIRS

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-defaults
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}/lib
CONFIGURE_ARGS+=	--with-sys-contact=${NET_SNMP_SYS_CONTACT:Q}
CONFIGURE_ARGS+=	--with-sys-location=${NET_SNMP_SYS_LOCATION:Q}
#
# NOTE:  if you specify a logfile then this file will be written to by
# default and although it can be disabled on the command line, the
# daemon must be stopped to cycle it properly.  Remember rc.d/snmpd
# will use '-s' to enable standard syslog logging anyway.
#
CONFIGURE_ARGS+=	--with-logfile=none
CONFIGURE_ARGS+=	--with-persistent-directory=${NET_SNMP_PERSISTENTDIR:Q}
.if !empty(NET_SNMP_MIBDIRS)
CONFIGURE_ARGS+=	--with-mibdirs=${NET_SNMP_MIBDIRS:Q}
.endif
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-mib-modules="smux host ucd-snmp/diskio"
.else
CONFIGURE_ARGS+=	--with-mib-modules="smux host"
.endif
.if !empty(MACHINE_PLATFORM:MDarwin-[567].*)
CONFIGURE_ARGS+=	--with-out-mib-modules="ucd-snmp/diskio mibII"
.endif
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
#
# Enable the perl modules build and installation
#
PERL5_CONFIGURE=	no
PERL5_PACKLIST=		auto/Bundle/NetSNMP/.packlist
CONFIGURE_ARGS+=	--with-perl-modules=${MAKE_PARAMS:Q}
CONFIGURE_ENV+=		PERLPROG=${PERL5:Q}

.include "options.mk"

# Handle ${PREFIX}/share/snmp in the DEINSTALL script since it may contain
# leftover config files or pidfiles after deinstallation.
#
REQD_DIRS=	${PREFIX}/share/snmp
RCD_SCRIPTS=	snmpd snmptrapd

USE_TOOLS+=		sh:run
REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	local/mib2c-update

INSTALLATION_DIRS+=	share/examples/net-snmp

post-extract:
	${CP} ${FILESDIR}/dragonfly.h ${WRKSRC}/include/net-snmp/system

post-wrapper:
.if !empty(MACHINE_PLATFORM:MNetBSD-1.5.[123]*-i386)
	${MKDIR} ${BUILDLINK_DIR}/include/sys
	${CP} ${FILESDIR}/disklabel.h ${BUILDLINK_DIR}/include/sys
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.conf	\
		${PREFIX}/share/examples/net-snmp/EXAMPLE.conf

.include "../../lang/perl5/module.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
