# $NetBSD: Makefile,v 1.76 2013/12/11 11:55:17 jperkin Exp $

DISTNAME=		apcupsd-3.14.9
PKGREVISION=		9
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=apcupsd/}

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.apcupsd.org/
COMMENT=		UPS power management for APCC Products

USE_TOOLS+=		gmake msgfmt sh makedepend
USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	apcupsd

.include "options.mk"

# Thread support is needed to compile powerflute, which has a curses
# interface (apparently needing ncurses), but pthreads isn't very
# efficient and is less preferred.
#
#.include "../../devel/ncurses/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-threads	# compile threading code
#CONFIGURE_ARGS+=	--enable-powerflute	# compile powerflute program

#CONFIGURE_ARGS+=	--with-net-port=${APCUPSD_NET_PORT}	# un-registered port is 7000

#CONFIGURE_ARGS+=	--with-nis-port=${APCUPSD_NIS_PORT}	# registered port is 3551
#CONFIGURE_ARGS+=	--with-upscable=${APCUPSD_UPS_CABLE}
#CONFIGURE_ARGS+=	--with-upscable=${APCUPSD_UPS_TYPE}

CONFIGURE_ARGS+=	--enable-net		# enable NIS network driver
CONFIGURE_ARGS+=	--enable-usb		# enable USB network driver
CONFIGURE_ARGS+=	--with-catgets		# use catgets functions
CONFIGURE_ARGS+=	--enable-nls		# i18n support
CONFIGURE_ARGS+=	--enable-snmp		# enable SNMP driver
CONFIGURE_ARGS+=	--with-lock-dir=${VARBASE}/spool/lock
# XXX is this supposed to be the full filename?
CONFIGURE_ARGS+=	--with-log-dir=${VARBASE}/db/apcupsd.events
# NOTE:  You want the /dev/ttyXX for smart cables such as 940-0024C,
# but probably the /dev/dtyXX for a basic smart-custom cable
CONFIGURE_ARGS+=	--with-serial-dev=/dev/tty01
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# configure sets sbindir to '${prefix}/sbin' without expanding $prefix
# this breaks .in files that uses @sbindir@
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin

CONFIGURE_ENV+=		SCRIPTSHELL=${TOOLS_SH:Q}
CONFIGURE_ENV+=		ac_cv_path_MAKE=${MAKE:Q} LD=${CXX}

EGDIR=		${PREFIX}/share/examples/apcupsd

CONF_FILES_PERMS+= ${EGDIR}/apcupsd.conf ${PKG_SYSCONFDIR}/apcupsd.conf ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644
CONF_FILES_PERMS+= ${EGDIR}/apcupsd.css ${PKG_SYSCONFDIR}/apcupsd.css ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644
CONF_FILES_PERMS+= ${EGDIR}/changeme ${PKG_SYSCONFDIR}/changeme ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/commfailure ${PKG_SYSCONFDIR}/commfailure ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/commok ${PKG_SYSCONFDIR}/commok ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/multimon.conf ${PKG_SYSCONFDIR}/multimon.conf  ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/hosts.conf ${PKG_SYSCONFDIR}/hosts.conf  ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/offbattery ${PKG_SYSCONFDIR}/offbattery ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/onbattery ${PKG_SYSCONFDIR}/onbattery ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/apccontrol ${PKG_SYSCONFDIR}/apccontrol ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755

RCD_SCRIPTS=	apcupsd
PLATFORM_SUBDIR=${OPSYS:tl}
.if ${OPSYS} == "DragonFly"
PLATFORM_SUBDIR=netbsd
.endif
.if ${OPSYS} == "SunOS"
PLATFORM_SUBDIR=sun
.endif
RCD_SCRIPT_SRC.apcupsd=	${WRKSRC}/platforms/${PLATFORM_SUBDIR}/apcupsd

EGFILES= ${PLATFORM_SUBDIR}/apccontrol etc/changeme etc/commfailure etc/commok \
    etc/offbattery etc/onbattery etc/multimon.conf etc/hosts.conf

INSTALLATION_DIRS=	share/examples/apcupsd share/examples/rc.d \
			share/doc/html/apcupsd share/doc/html/apcupsd/manual

SUBST_CLASSES+=		strip
SUBST_STAGE.strip=	pre-configure
SUBST_FILES.strip=	autoconf/install-sh autoconf/targets.mak
SUBST_FILES.strip+=	src/gapcmon/Makefile.in src/cgi/Makefile.in
SUBST_FILES.strip+=	src/Makefile.in
SUBST_SED.strip=	-e "s|STRIP|STRIPFLAG|g"
SUBST_MESSAGE.strip=	Fixing conflicting STRIP variable name

# XXX we should probably allow the tty to be set in /etc/mk.conf too
#

HTMLDOCS= apcupsd.gif bclogo.gif bugs.html index.html license.html \
	lists.html mail16d.png support.html systems.html
HTMLMANUALS=	manual.html apcupsd.png charging.png commlost.png \
	main_configs.png multimon.png onbatt.png online.png status.png \
	thanks.png wininstall6.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/platforms/etc/apcupsd.conf \
		${DESTDIR}${PREFIX}/share/examples/apcupsd
	${INSTALL_DATA} ${WRKSRC}/src/cgi/apcupsd.css \
		${DESTDIR}${PREFIX}/share/examples/apcupsd
.for file in ${EGFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/platforms/${file} \
		${DESTDIR}${PREFIX}/share/examples/apcupsd
.endfor
.for file in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/home-page/${file} \
		${DESTDIR}${PREFIX}/share/doc/html/apcupsd
.endfor
.for file in ${HTMLMANUALS}
	${INSTALL_DATA} ${WRKSRC}/doc/manual/${file} \
		${DESTDIR}${PREFIX}/share/doc/html/apcupsd/manual
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
