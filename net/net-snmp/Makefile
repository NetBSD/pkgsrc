# $NetBSD: Makefile,v 1.1.1.1 2002/10/24 08:29:33 jlam Exp $

DISTNAME=	net-snmp-5.0.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=net-snmp/} \
		ftp://ftp.net-smnp.org/pub/sourceforge/net-snmp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.net-snmp.org/
COMMENT=	Extensible SNMP implementation

CONFLICTS=	ucd-snmp-[0-9]*

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

NET_SNMP_SYS_CONTACT?=		default_user@contact.domain
NET_SNMP_SYS_LOCATION?=		defaultlocation
NET_SNMP_LOGFILE?=		/var/log/snmpd.log
NET_SNMP_PERSISTENTDIR?=	/var/net-snmp
NET_SNMP_MIBDIRS?=		\$$HOME/.snmp/mibs:${PREFIX}/share/snmp/mibs

USE_BUILDLINK2=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.if (${OPSYS} == "NetBSD")
CFLAGS+=		-Dnetbsd1
.endif

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-shared
.if defined(USE_INET6) && (${USE_INET6} == "YES")
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
CONFIGURE_ARGS+=	--with-defaults
CONFIGURE_ARGS+=	--with-libwrap
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--with-sys-contact="${NET_SNMP_SYS_CONTACT}"
CONFIGURE_ARGS+=	--with-sys-location="${NET_SNMP_SYS_LOCATION}"
CONFIGURE_ARGS+=	--with-logfile="${NET_SNMP_LOGFILE}"
CONFIGURE_ARGS+=	--with-persistent-directory="${NET_SNMP_PERSISTENTDIR}"
.if !empty(NET_SNMP_MIBDIRS)
CONFIGURE_ARGS+=	--with-mibdirs="${NET_SNMP_MIBDIRS}"
.endif
#
# Using "dummy" values is technically not compliant with SNMP specs, but
# otherwise, some tools, e.g. net/tcl-scotty, net/tkined, may ignore results
# when they shouldn't.
#
CONFIGURE_ARGS+=	--with-dummy-values

.if !exists(/usr/bin/lpstat)
CONFIGURE_ENV+=		ac_cv_path_LPSTAT_PATH=no
.endif
CONFIGURE_ENV+=		PERLPROG="${PERL5}"

# Handle ${PREFIX}/share/snmp in the DEINSTALL script since it may contain
# leftover config files or pidfiles after deinstallation.
#
OWN_DIRS=	${PREFIX}/share/snmp
RCD_SCRIPTS=	snmpd snmptrapd

pre-configure:
.if !empty(MACHINE_PLATFORM:MNetBSD-1.5.[123]*-i386)
	${MKDIR} ${BUILDLINK_DIR}/include/sys
	${CP} ${FILESDIR}/disklabel.h ${BUILDLINK_DIR}/include/sys
.endif
.if ${OPSYS} == SunOS
	#
	# Adapt for the fact that the default I've seen of ac_max_sed_cmds=90
	# will not work w/ built-in sed on Solaris.
	#
	cd ${WRKSRC}; for file in ${CONFIGURE_SCRIPT}; do		\
		${SED}	-e "s|ac_max_sed_cmds=[0-9][0-9]*|ac_max_sed_cmds=10|" \
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/net-snmp
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.conf				\
		${PREFIX}/share/examples/net-snmp/EXAMPLE.conf

.include "../../lang/perl5/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
