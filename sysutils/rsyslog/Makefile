# $NetBSD: Makefile,v 1.3 2015/01/16 16:58:28 fhajny Exp $
#

BUILDLINK_DEPMETHOD.libestr=	full
BUILDLINK_DEPMETHOD.liblogging=	full
BUILDLINK_DEPMETHOD.libuuid=	full

.include "../../sysutils/rsyslog/Makefile.common"

COMMENT=		The enhanced syslogd for Unix

CONFIGURE_ARGS+=	--disable-testbench --enable-cached-man-pages		\
			--enable-diagtools --enable-usertools --enable-uuid	\
			--enable-imdiag --enable-imfile	--enable-impstats	\
			--enable-mail --enable-mmjsonparse --enable-mmnormalize	\
			--enable-omstdout

PLIST_VARS+=		klog solaris

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-imsolaris --disable-klog
PLIST.solaris=		yes
RSYSLOG_SYSMOD=		imsolaris
.else
CONFIGURE_ARGS+=	--disable-imsolaris --enable-klog
PLIST.klog=		yes
RSYSLOG_SYSMOD=		imklog
.endif

BUILD_DEFS+=		VARBASE RSYSLOG_PIDDIR RSYSLOG_WRKDIR
RSYSLOG_PIDDIR?=	${VARBASE}/run
RSYSLOG_WRKDIR?=	${VARBASE}/lib/rsyslog
OWN_DIRS+=		${RSYSLOG_PIDDIR} ${RSYSLOG_WRKDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	platform/redhat/rsyslog.conf tools/rsyslog.conf.5
SUBST_FILES.paths+=	tools/rsyslogd.8 tools/rsyslogd.c tools/syslogd.c
SUBST_VARS.paths=	RSYSLOG_PIDDIR RSYSLOG_SYSMOD
SUBST_SED.paths=	-e "s|/etc|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.paths=	Setting default paths and options.

RCD_SCRIPTS=		rsyslogd

CONF_FILES+=		share/examples/rsyslog/rsyslog.conf 			\
			${PKG_SYSCONFDIR}/rsyslog.conf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/platform/redhat/rsyslog.conf			\
		${DESTDIR}${EGDIR}/rsyslog.conf

BUILDLINK_ABI_DEPENDS.liblognorm+=	liblognorm>=1.0.2
.include "../../sysutils/liblognorm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
