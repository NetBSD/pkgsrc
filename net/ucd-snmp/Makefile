# $NetBSD: Makefile,v 1.46 2002/08/25 18:39:39 jlam Exp $

DISTNAME=	ucd-snmp-4.2.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=net-snmp/} \
		ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.or.jp/pub/network/snmp/ucd-snmp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.net-snmp.org/
COMMENT=	Extensible SNMP implementation

CONFLICTS+=	net-snmp-[0-9]*

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf

BUILD_DEFS+=	USE_INET6

USE_BUILDLINK2=	# defined

.include "../../mk/bsd.prefs.mk"

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-defaults
CONFIGURE_ARGS+=	--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
CONFIGURE_ARGS+=	--with-logfile="/var/log/snmpd"
CONFIGURE_ARGS+=	--with-mib-modules="smux host"
#
# NOTE: if you do not allow dummy values some tools such as
# scotty/tkined may ignore results when they shouldn't.
#
CONFIGURE_ARGS+=	--with-dummy-values
#
# NOTE: without this the default is USER@DOMAINNAME of the package builder
#
CONFIGURE_ARGS+=	--with-sys-contact="default_user@contact.domain"
CONFIGURE_ARGS+=	--with-sys-location="defaultlocation"
CONFIGURE_ARGS+=	--enable-shared
.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

# This might make it easier to use scotty's MIBs and local MIBs.
CONFIGURE_ARGS+=	--with-mibdirs="${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tcl/tnm2.1.10/mibs:${PREFIX}/lib/tnm2.1.8/mibs:/usr/local/share/snmp/mibs"

.if (${OPSYS} == "NetBSD")
CFLAGS+=	-Dnetbsd1
.endif

# Deal with libwrap bogosity by providing these variables to programs which
# do not supply them.
#
post-extract:
	@${ECHO} 'int allow_severity, deny_severity;'			\
		> ${WRKSRC}/snmplib/libwrap.c
	@${LN} ${WRKSRC}/s/netbsd.h ${WRKSRC}/s/netbsdelf.h

pre-configure:
.if (${OPSYS} == NetBSD)
	if [ -f /usr/include/uvm/uvm_param.h ]; then			\
		cd ${BUILDLINK_DIR}/include;				\
		${MKDIR} vm;						\
		${LN} -s /usr/include/uvm/uvm_param.h vm/vm_param.h;	\
	fi
.  if (${LOWER_ARCH} == i386 && ${OS_VERSION:M1.5.[123]*} != "")
	${MKDIR} ${BUILDLINK_DIR}/include/sys
	${LN} -s ${FILESDIR}/disklabel.h ${BUILDLINK_DIR}/include/sys
.  endif
.endif
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf
#
# Adapt for the fact that the default I've seen of ac_max_sed_cmds=90
# will not work w/ built-in sed on Solaris.
#
.if ${OPSYS} == SunOS
	cd ${WRKSRC};							\
	${SED}	's/ac_max_sed_cmds=[0-9][0-9]*/ac_max_sed_cmds=10/'	\
		${CONFIGURE_SCRIPT} > ${CONFIGURE_SCRIPT}.fixed;	\
	${MV} -f ${CONFIGURE_SCRIPT}.orig ${CONFIGURE_SCRIPT}
.endif

post-build:
	${SED} 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/snmpd.sh > ${WRKDIR}/snmpd
	${SED} 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/snmptrapd.sh > ${WRKDIR}/snmptrapd

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ucd-snmp
	${INSTALL_DATA} ${WRKSRC}/EXAMPLE.conf ${PREFIX}/share/examples/ucd-snmp
	${INSTALL_DATA_DIR} ${PREFIX}/lib/snmp/dlmod
	${INSTALL_SCRIPT} ${WRKDIR}/snmpd ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKDIR}/snmptrapd ${PREFIX}/etc/rc.d

.include "../../security/openssl/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
