# $NetBSD: Makefile,v 1.45 2006/11/15 21:46:24 bouyer Exp $

DISTNAME=		apcupsd-3.12.4
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=apcupsd/}

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.apcupsd.org/
COMMENT=		UPS power management for APCC Products

USE_TOOLS+=		gmake msgfmt sh
USE_LANGUAGES+=		c++

GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR= apcupsd

# Thread support is needed to for http support, and to compile powerflute,
# which has a curses interface
#
#CONFIGURE_ARGS+=	--enable-http		# include http support
#.include "../../devel/ncurses/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-threads	# compile threading code
#CONFIGURE_ARGS+=	--enable-powerflute	# compile powerflute program

CONFIGURE_ARGS+=	--enable-net		# enable NIS network driver
#CONFIGURE_ARGS+=	--enable-snmp		# enable SNMP driver
CONFIGURE_ARGS+=	--with-catgets		# use catgets functions
CONFIGURE_ARGS+=	--enable-nls		# i18n support
CONFIGURE_ARGS+=	--with-lock-dir=${VARBASE}/spool/lock
CONFIGURE_ARGS+=	--with-serial-dev=/dev/tty01
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
# configure sets sbindir to '${prefix}/sbin' without expanding $prefix
# this breaks .in files that uses @sbindir@
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin

CONFIGURE_ENV+=		SCRIPTSHELL=${TOOLS_SH:Q}

EGDIR=          ${PREFIX}/share/examples/apcupsd

CONF_FILES_PERMS+= ${EGDIR}/apcupsd.master.conf ${PKG_SYSCONFDIR}/apcupsd.conf ${ROOT_USER} ${ROOT_GROUP} 644
CONF_FILES_PERMS+= ${EGDIR}/changeme ${PKG_SYSCONFDIR}/changeme ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/commfailure ${PKG_SYSCONFDIR}/commfailure ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/commok ${PKG_SYSCONFDIR}/commok ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/masterconnect ${PKG_SYSCONFDIR}/masterconnect ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/mastertimeout ${PKG_SYSCONFDIR}/mastertimeout ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/offbattery ${PKG_SYSCONFDIR}/offbattery ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/onbattery ${PKG_SYSCONFDIR}/onbattery ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/apccontrol ${PKG_SYSCONFDIR}/apccontrol ${ROOT_USER} ${ROOT_GROUP} 755
RCD_SCRIPTS=	apcupsd
RCD_SCRIPT_SRC.apcupsd=	${WRKSRC}/distributions/netbsd/apcupsd

EGFILES= netbsd/apccontrol etc/changeme etc/commfailure etc/commok \
    etc/masterconnect etc/mastertimeout etc/offbattery etc/onbattery
MANFILES= apcupsd apctest

# we should probably allow the tty to be set in /etc/mk.conf too
#
post-build:
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' \
		${WRKSRC}/examples/apcupsd.master.conf > \
		${WRKDIR}/apcupsd.master.conf
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' \
		${WRKSRC}/examples/apcupsd.slave.conf > \
		${WRKDIR}/apcupsd.slave.conf
.for file in ${MANFILES}
	${SED} -e 's|@@PREFIX@@|${PREFIX}|'\
	     -e 's|@@SYSCONFDIR@@|${PKG_SYSCONFDIR}|' \
	     ${WRKSRC}/doc/${file}.man > ${WRKSRC}/doc/${file}.8
.endfor

HTMLDOCS= apcupsd.gif bclogo.gif bugs.html bugs.wml index.html index.wml \
    license.html license.wml lists.html lists.wml mail16d.png menu.inc \
    publishsite support.html support.wml systems.html systems.wml template.inc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/apcupsd
	${INSTALL_DATA} ${WRKDIR}/apcupsd.master.conf \
		${PREFIX}/share/examples/apcupsd
	${INSTALL_DATA} ${WRKDIR}/apcupsd.slave.conf \
		${PREFIX}/share/examples/apcupsd
.for file in ${EGFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/platforms/${file} \
		${PREFIX}/share/examples/apcupsd
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/platforms/netbsd/apcupsd \
	    ${PREFIX}/share/examples/rc.d
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/apcupsd
.for file in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/home-page/${file} \
		${PREFIX}/share/doc/html/apcupsd
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
