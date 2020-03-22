# $NetBSD: Makefile,v 1.24 2020/03/22 23:39:13 rillig Exp $
#

BUILDLINK_DEPMETHOD.libestr=	full
BUILDLINK_DEPMETHOD.libuuid=	full

PKGREVISION= 8
.include "../../sysutils/rsyslog/Makefile.common"

COMMENT=		The enhanced syslogd for Unix

CONFIGURE_ARGS+=	--disable-testbench					\
			--enable-diagtools --enable-usertools --enable-uuid	\
			--enable-imdiag --enable-imfile	--enable-impstats	\
			--enable-mail --enable-mmjsonparse --enable-mmnormalize	\
			--enable-omstdout

PLIST_VARS+=		klog solaris

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-imsolaris --disable-klog
# Explicitly disable epoll/inotify on illumos, provided for Linux compat only.
CONFIGURE_ENV+=		ac_cv_func_epoll_create=no
CONFIGURE_ENV+=		ac_cv_func_epoll_create1=no
CONFIGURE_ENV+=		ac_cv_func_inotify_init=no
CONFIGURE_ENV+=		ac_cv_header_sys_inotify_h=no
PLIST.solaris=		yes
RSYSLOG_SYSMOD=		imsolaris
.else
CONFIGURE_ARGS+=	--disable-imsolaris --enable-klog
PLIST.klog=		yes
RSYSLOG_SYSMOD=		imklog
.endif

# needs to be able to do compare-and-swap on time_t (cmpxchg8b)
.if ${MACHINE_ARCH} == "i386"
CFLAGS+=		-march=i586
.endif

BUILDLINK_TRANSFORM.Darwin+=	rm:-luuid

BUILD_DEFS+=		VARBASE RSYSLOG_PIDDIR RSYSLOG_WRKDIR
RSYSLOG_PIDDIR?=	${VARBASE}/run
RSYSLOG_WRKDIR?=	${VARBASE}/lib/rsyslog
OWN_DIRS+=		${RSYSLOG_PIDDIR} ${RSYSLOG_WRKDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	platform/redhat/rsyslog.conf tools/rsyslog.conf.5
SUBST_FILES.paths+=	tools/rsyslogd.8 tools/rsyslogd.c
SUBST_VARS.paths=	RSYSLOG_PIDDIR RSYSLOG_SYSMOD
SUBST_SED.paths=	-e "s|/etc|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.paths=	Setting default paths and options.
# FIXME: This also replaces /etc/timezone, which is probably unintended.

SUBST_CLASSES.Darwin+=	ldargs
SUBST_STAGE.ldargs=	pre-configure
SUBST_FILES.ldargs=	tools/Makefile.in
SUBST_SED.ldargs=	-e '/whole-archive.*librsyslog/d'

RCD_SCRIPTS=		rsyslogd

CONF_FILES+=		share/examples/rsyslog/rsyslog.conf 			\
			${PKG_SYSCONFDIR}/rsyslog.conf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/platform/redhat/rsyslog.conf			\
		${DESTDIR}${EGDIR}/rsyslog.conf

BUILDLINK_API_DEPENDS.liblognorm+=	liblognorm>=2.0.3
.include "../../sysutils/liblognorm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
