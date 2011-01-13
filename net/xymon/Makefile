# $NetBSD: Makefile,v 1.6 2011/01/13 13:39:08 wiz Exp $
#

DISTNAME=		xymon-4.3.0-beta2
PKGNAME=		xymon-4.3.0b2
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=hobbitmon/}

MAINTAINER=		spz@NetBSD.org
HOMEPAGE=		http://hobbitmon.sourceforge.net/
COMMENT=		Network services monitor a la Big Brother
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		NO

CONFLICTS+=		hobbitmon-[0-9]*
CONFLICTS+=		hobbitclient-[0-9]*

DEPENDS+=		fping>2:../../net/fping
	# xymonclient ought to be the same version as the server, modulo nbN
DEPENDS+=		xymonclient>=4.3.0b2:../../net/xymonclient

HAS_CONFIGURE=		YES
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

# xymons user/group

BBUSER?=		xymon
BBGROUP?=		xymon

PKG_GROUPS=		${BBGROUP}
PKG_USERS=		${BBUSER:Q}:${BBGROUP:Q}

PKG_GECOS.${BBUSER}=	Xymon monitor
PKG_HOME.${BBUSER}=	${BBHOME}

PKG_GROUPS_VARS+=	BBGROUP
PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	BBUSER

# startup and config

RCD_SCRIPTS+=		xymon
PKG_SYSCONFDIR.xymon=	${PREFIX}/etc/xymon
EXAMPLEDIR=		${PREFIX}/share/examples/xymon

INSTALLATION_DIRS+=	${EXAMPLEDIR}
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR.xymon}

BBHOME?=		${PREFIX}/share/xymon/bbhome
BBTOPDIR?=		${PREFIX}/libexec/xymon
BBHOSTURL?=		/
CGIDIR?=		${BBTOPDIR}/cgi-bin
BBCGIURL?=		/cgi-bin
SECCGIDIR?=		${BBTOPDIR}/cgi-secure
SECUREBBCGIURL?=	/xymon-seccgi

BBSERVERNAME?=		"`uname -n`"
BBSERVERIP?=		127.0.0.1

BBLOGDIR?=		${VARBASE}/log/xymon
BBVAR?=			${VARBASE}/xymon

XYBINDIR?=		${BBTOPDIR}
XYETCDIR?=		${PKG_SYSCONFDIR.xymon}
XYEXTDIR?=		${BBTOPDIR}/ext
XYTMPDIR?=		${VARBASE}/xymon/tmp
XYWEBDIR?=		${PREFIX}/share/xymon/web
XYWWWDIR?=		${VARBASE}/xymon/www

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		BBHOSTURL
BUILD_DEFS+=		BBSERVERNAME
BUILD_DEFS+=		BBSERVERIP

FILES_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR}
FILES_SUBST+=		BBHOME=${BBHOME:Q}
FILES_SUBST+=		BBLOGDIR=${BBLOGDIR}
FILES_SUBST+=		BBVAR=${BBVAR:Q}
FILES_SUBST+=		XYBINDIR=${XYBINDIR}
FILES_SUBST+=		XYETCDIR=${XYETCDIR}
FILES_SUBST+=		XYEXTDIR=${XYEXTDIR}
FILES_SUBST+=		XYTMPDIR=${XYTMPDIR}
FILES_SUBST+=		XYWEBDIR=${XYWEBDIR}
FILES_SUBST+=		XYWWWDIR=${XYWWWDIR}

MESSAGE_SUBST+=		SECCGIDIR=${SECCGIDIR}

EVAL_PREFIX+=		PREFIX.fping=fping

CONFIGURE_ARGS+=	"--server"

CONFIGURE_ENV+=		USERFPING=${PREFIX.fping}/sbin/fping
CONFIGURE_ENV+=		USEHOBBITPING=n
CONFIGURE_ENV+=		RRDINC=${BUILDLINK_PREFIX.rrdtool}/include
CONFIGURE_ENV+=		RRDLIB=${BUILDLINK_PREFIX.rrdtool}/lib/librrd.a
CONFIGURE_ENV+=		PNGLIB=${BUILDLINK_PREFIX.png}/lib/libpng.a
CONFIGURE_ENV+=		ENABLESSL=y
CONFIGURE_ENV+=		OSSLINC=${BUILDLINK_PREFIX.openssl}/include
CONFIGURE_ENV+=		OSSLLIB=${BUILDLINK_PREFIX.openssl}/lib
CONFIGURE_ENV+=		ENABLELDAP=y
CONFIGURE_ENV+=		ENABLELDAPSSL=y
CONFIGURE_ENV+=		LDAPINC=${BUILDLINK_PREFIX.openldap-client}/include
CONFIGURE_ENV+=		LDAPLIB=${BUILDLINK_PREFIX.openldap-client}/lib
CONFIGURE_ENV+=		PCREINC=${BUILDLINK_PREFIX.pcre}/include
CONFIGURE_ENV+=		PCRELIB=${BUILDLINK_PREFIX.pcre}/lib
CONFIGURE_ENV+=		BBHOSTNAME=${BBSERVERNAME:Q}
CONFIGURE_ENV+=		BBHOSTIP=${BBSERVERIP:Q}
CONFIGURE_ENV+=		BBUSER=${BBUSER:Q}
CONFIGURE_ENV+=		BBHOME=${BBHOME:Q}
CONFIGURE_ENV+=		BBTOPDIR=${BBTOPDIR}
CONFIGURE_ENV+=		BBHOSTURL=${BBHOSTURL:Q}
CONFIGURE_ENV+=		CGIDIR=${CGIDIR}
CONFIGURE_ENV+=		BBCGIURL=${BBCGIURL:Q}
CONFIGURE_ENV+=		SECURECGIDIR=${SECCGIDIR}
CONFIGURE_ENV+=		SECUREBBCGIURL=${SECUREBBCGIURL:Q}
CONFIGURE_ENV+=		HTTPDGID=${APACHE_GROUP}
CONFIGURE_ENV+=		BBLOGDIR=${BBLOGDIR}
CONFIGURE_ENV+=		BBVAR=${BBVAR:Q}
CONFIGURE_ENV+=		INSTALLROOT=${DESTDIR}
CONFIGURE_ENV+=		INSTALLBINDIR=${XYBINDIR}
CONFIGURE_ENV+=		INSTALLETCDIR=${XYETCDIR}
CONFIGURE_ENV+=		INSTALLEXADIR=${EXAMPLEDIR}
CONFIGURE_ENV+=		INSTALLEXTDIR=${XYEXTDIR}
CONFIGURE_ENV+=		INSTALLTMPDIR=${XYTMPDIR}
CONFIGURE_ENV+=		INSTALLWEBDIR=${XYWEBDIR}
CONFIGURE_ENV+=		INSTALLWWWDIR=${XYWWWDIR}
CONFIGURE_ENV+=		MANROOT=${PREFIX}/${PKGMANDIR}/

SUBST_CLASSES+=		bashpath
SUBST_FILES.bashpath=	hobbitd/hobbitreports.sh.DIST
SUBST_SED.bashpath=	-e 's,/bin/bash,'${BASH:Q}','
SUBST_STAGE.bashpath=	post-patch

USE_TOOLS+=	awk:run		cat:run		cp:run
USE_TOOLS+=	cut:run		date:run	egrep:run
USE_TOOLS+=	expr:run	find:run	grep:run
USE_TOOLS+=	head:run	id:run		ls:run
USE_TOOLS+=	mv:run		rm:run		sed:run
USE_TOOLS+=	sort:run	tail:run	touch:run
USE_TOOLS+=	tr:run		wc:run		bash:run


MAKE_DIRS+=		${BBTOPDIR}
MAKE_DIRS+=		${BBHOME}

OWN_DIRS_PERMS+=	${XYEXTDIR} ${BBUSER} ${BBGROUP} 0755
OWN_DIRS_PERMS+=	${BBLOGDIR} ${BBUSER} ${BBGROUP} 0755
OWN_DIRS_PERMS+=	${XYTMPDIR} ${BBUSER} ${BBGROUP} 0755

OWN_DIRS_PERMS+=	${BBVAR} ${BBUSER} ${BBGROUP} 0755
VAR_SUBDIRS=		acks data disabled download hist histlogs hostdata rrd
.for dir in ${VAR_SUBDIRS}
OWN_DIRS_PERMS+=	${BBVAR}/${dir} ${BBUSER} ${BBGROUP} 0755
.endfor

OWN_DIRS_PERMS+=	${XYWWWDIR} ${BBUSER} ${BBGROUP} 0755
WWW_SUBDIRS=		gifs help html menu notes wml
.for dir in ${WWW_SUBDIRS}
OWN_DIRS_PERMS+=	${XYWWWDIR}/${dir} ${BBUSER} ${BBGROUP} 0755
.endfor
OWN_DIRS_PERMS+=	${XYWWWDIR}/rep ${BBUSER} ${APACHE_GROUP} 0755
OWN_DIRS_PERMS+=	${XYWWWDIR}/snap ${BBUSER} ${APACHE_GROUP} 0755

MAKE_DIRS_PERMS+=	${SECCGIDIR} root ${BBGROUP} 0000

# actual config files

CFILES=			bb-hosts bb-services bbcombotest.cfg client-local.cfg
CFILES+=		columndoc.csv hobbit-alerts.cfg hobbit-apache.conf
CFILES+=		hobbit-clients.cfg hobbit-nkview.cfg hobbitcgi.cfg
CFILES+=		hobbitgraph.cfg hobbitlaunch.cfg hobbitserver.cfg
.for file in ${CFILES}
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${file} ${PKG_SYSCONFDIR.xymon}/${file} ${BBUSER} ${BBGROUP} 0644
.endfor

MAKE_ENV+=		MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=		PKGDIR=${PREFIX}
MAKE_ENV+=		INSTALLROOT=${DESTDIR}
MAKE_ENV+=		PKGBUILD=y
MAKE_ENV+=		${TOOLS_ENV}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/apache.mk"

.include "../../mk/bsd.pkg.mk"
