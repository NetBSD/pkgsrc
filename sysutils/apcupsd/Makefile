# $NetBSD: Makefile,v 1.27 2004/04/25 09:14:00 snj Exp $

DISTNAME=		apcupsd-3.8.6
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=apcupsd/}

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.sibbald.com/apcupsd/
COMMENT=		UPS power management for APCC Products

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR= apcupsd

# Thread support is needed to for http support, and to compile powerflute,
# which has a curses interface
#
#CONFIGURE_ARGS+=	--enable-http		# include http support
#.include "../../devel/ncurses/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-threads	# compile threading code
#CONFIGURE_ARGS+=	--enable-powerflute	# compile powerflute program

CONFIGURE_ARGS+=	--with-catgets		# use catgets functions
CONFIGURE_ARGS+=	--enable-nls		# i18n support
CONFIGURE_ARGS+=	--with-lock-dir=/var/spool/lock
CONFIGURE_ARGS+=	--with-serial-dev=/dev/tty01
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
# configure sets sbindir to '${prefix}/sbin' without expanding $prefix
# this breaks .in files that uses @sbindir@
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin

EGDIR=          ${PREFIX}/share/examples/apcupsd

CONF_FILES_PERMS+=     ${EGDIR}/apcupsd.master.conf ${PKG_SYSCONFDIR}/apcupsd.conf ${ROOT_USER} ${ROOT_GROUP} 644
CONF_FILES_PERMS+= ${EGDIR}/changeme ${PKG_SYSCONFDIR}/changeme ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/commfailure ${PKG_SYSCONFDIR}/commfailure ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/commok ${PKG_SYSCONFDIR}/commok ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/onbattery ${PKG_SYSCONFDIR}/onbattery ${ROOT_USER} ${ROOT_GROUP} 755
CONF_FILES_PERMS+= ${EGDIR}/mainsback ${PKG_SYSCONFDIR}/mainsback ${ROOT_USER} ${ROOT_GROUP} 755
SUPPORT_FILES_PERMS=  ${EGDIR}/apccontrol ${PKG_SYSCONFDIR}/apccontrol ${ROOT_USER} ${ROOT_GROUP} 755
RCD_SCRIPTS=	apcupsd

# we should probably allow the tty to be set in /etc/mk.conf too
#
post-build:
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' \
		${WRKSRC}/examples/apcupsd.master.conf > \
		${WRKDIR}/apcupsd.master.conf
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' \
		${WRKSRC}/examples/apcupsd.slave.conf > \
		${WRKDIR}/apcupsd.slave.conf
	${SED} -e 's|@@PREFIX@@|${PREFIX}|'\
	     -e 's|@@SYSCONFDIR@@|${PKG_SYSCONFDIR}|' \
	     ${WRKSRC}/doc/apcupsd.man > ${WRKSRC}/doc/apcupsd.8

DOCS=	README.BackUPS		\
	README.BackUPS-Pro	\
	README.NewerBackUPS-Pro	\
	README.Share-UPS	\
	README.SmartUPS-VS	\
	README.apcaccess	\
	README.autoconfig	\
	README.cable		\
	Statement.APCC 		\
	apcupsd-bug-1 		\
	apcupsd-bug-2 		\
	minicom.txt		\
	port.gif

HTMLDOCS= apcaccess.html apcnisd.html apctest.html apcupsd-styles.css \
	 apcupsd.book apcupsd.gif apcupsd.html batteries.html bugs.html \
	 cables.html cgiprogs.html charging.gif config-examples.html \
	 configure.html data.html eprom.html events.html faq.html index.html \
	 install.html invoking.html kernel_config.html license.html \
	 logging.html master-slave.html multiUPS.html multimon.gif \
	 new_features_3_7_0.html new_features_3_8_0.html \
	 new_features_3_8_1.html new_features_3_8_2.html \
	 new_features_3_8_3.html new_features_3_8_4.html \
	 new_features_3_8_5.html oldversions.html onbatt.gif online.gif \
	 security.html shutdown.html status.gif status.html stopping.html \
	 testing.html thanks.gif thanks.html troubles.html \
	 upgrading_to_3_7_0.html upsbible.html usb.html win32.html \
	 wininstall1.gif wininstall2.gif wininstall3.gif wininstall4.gif \
	 wininstall5.gif wininstall6.gif wininstall7.gif

post-install:
	${INSTALL_DATA} ${WRKDIR}/apcupsd.master.conf \
		${PREFIX}/share/examples/apcupsd
	${INSTALL_DATA} ${WRKDIR}/apcupsd.slave.conf \
		${PREFIX}/share/examples/apcupsd
	${INSTALL_SCRIPT} ${WRKSRC}/distributions/netbsd/apcupsd \
		${PREFIX}/etc/rc.d
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/apcupsd
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/apcupsd
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/apcupsd
.for file in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/manual/${file} \
		${PREFIX}/share/doc/html/apcupsd
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
