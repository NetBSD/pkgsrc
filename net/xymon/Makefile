# $NetBSD: Makefile,v 1.44 2016/02/16 05:58:56 spz Exp $
#

DISTNAME=		xymon-4.3.25
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xymon/}

MAINTAINER=		spz@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/xymon/
COMMENT=		Network services monitor a la Big Brother
LICENSE=		gnu-gpl-v2

MAKE_JOBS_SAFE=		NO

CONFLICTS+=		hobbitmon-[0-9]*
CONFLICTS+=		hobbitclient-[0-9]*

DEPENDS+=		fping>=2:../../net/fping
	# xymonclient ought to be the same version as the server, modulo nbN
DEPENDS+=		xymonclient>=4.3.0b2:../../net/xymonclient

HAS_CONFIGURE=		YES
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

# xymons user/group

XYMONUSER?=		xymon
XYMONGROUP?=		xymon

PKG_GROUPS=		${XYMONGROUP}
PKG_USERS=		${XYMONUSER:Q}:${XYMONGROUP:Q}

PKG_GECOS.${XYMONUSER}=	Xymon monitor
PKG_HOME.${XYMONUSER}=	${XYMONHOME}

PKG_GROUPS_VARS+=	XYMONGROUP
PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	XYMONUSER

# startup and config

RCD_SCRIPTS+=		xymon
PKG_SYSCONFDIR.xymon=	${PREFIX}/etc/xymon
EXAMPLEDIR=		${PREFIX}/share/examples/xymon

INSTALLATION_DIRS+=	${EXAMPLEDIR}
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR.xymon}

XYMONHOME?=		${PREFIX}/share/xymon/xymonhome
XYMONTOPDIR?=		${PREFIX}/libexec/xymon
XYMONHOSTURL?=		/
CGIDIR?=		${XYMONTOPDIR}/cgi-bin
XYMONCGIURL?=		/cgi-bin
SECCGIDIR?=		${XYMONTOPDIR}/cgi-secure
SECUREXYMONCGIURL?=	/xymon-seccgi

XYMONSERVERNAME?=	"`uname -n`"
XYMONSERVERIP?=		127.0.0.1

XYMONLOGDIR?=		${VARBASE}/log/xymon
XYMONVAR?=		${VARBASE}/xymon

XYBINDIR?=		${XYMONTOPDIR}
XYETCDIR?=		${PKG_SYSCONFDIR.xymon}
XYEXTDIR?=		${XYMONTOPDIR}/ext
XYTMPDIR?=		${VARBASE}/xymon/tmp
XYWEBDIR?=		${PREFIX}/share/xymon/web
XYWWWDIR?=		${VARBASE}/xymon/www

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		XYMONHOSTURL
BUILD_DEFS+=		XYMONSERVERNAME
BUILD_DEFS+=		XYMONSERVERIP

FILES_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR}
FILES_SUBST+=		XYMONHOME=${XYMONHOME:Q}
FILES_SUBST+=		XYMONLOGDIR=${XYMONLOGDIR}
FILES_SUBST+=		XYMONVAR=${XYMONVAR:Q}
FILES_SUBST+=		XYBINDIR=${XYBINDIR}
FILES_SUBST+=		XYETCDIR=${XYETCDIR}
FILES_SUBST+=		XYEXTDIR=${XYEXTDIR}
FILES_SUBST+=		XYTMPDIR=${XYTMPDIR}
FILES_SUBST+=		XYWEBDIR=${XYWEBDIR}
FILES_SUBST+=		XYWWWDIR=${XYWWWDIR}

MESSAGE_SUBST+=		DESTDIR=${DESTDIR}
MESSAGE_SUBST+=		EXAMPLEDIR=${EXAMPLEDIR}
MESSAGE_SUBST+=		SECCGIDIR=${SECCGIDIR}

CONFIGURE_ARGS+=	"--server"
CONFIGURE_ARGS+=	"--rrdinclude" "${BUILDLINK_PREFIX.rrdtool}/include"
CONFIGURE_ARGS+=	"--rrdlib" "${BUILDLINK_PREFIX.rrdtool}/lib"
CONFIGURE_ARGS+=	"--pngconfig" "${BUILDLINK_PREFIX.png}/bin/libpng-config"
CONFIGURE_ARGS+=	"--pcreinclude" "${BUILDLINK_PREFIX.pcre}/include"
CONFIGURE_ARGS+=	"--pcrelib" "${BUILDLINK_PREFIX.pcre}/lib"
CONFIGURE_ARGS+=	"--fping" "${LOCALBASE}/sbin/fping"

CONFIGURE_ENV+=		USEXYMONPING=n
CONFIGURE_ENV+=		XYMONHOSTNAME=${XYMONSERVERNAME:Q}
CONFIGURE_ENV+=		XYMONHOSTIP=${XYMONSERVERIP:Q}
CONFIGURE_ENV+=		XYMONUSER=${XYMONUSER:Q}
CONFIGURE_ENV+=		XYMONHOME=${XYMONHOME:Q}
CONFIGURE_ENV+=		XYMONTOPDIR=${XYMONTOPDIR}
CONFIGURE_ENV+=		XYMONHOSTURL=${XYMONHOSTURL:Q}
CONFIGURE_ENV+=		CGIDIR=${CGIDIR}
CONFIGURE_ENV+=		XYMONCGIURL=${XYMONCGIURL:Q}
CONFIGURE_ENV+=		SECURECGIDIR=${SECCGIDIR}
CONFIGURE_ENV+=		SECUREXYMONCGIURL=${SECUREXYMONCGIURL:Q}
CONFIGURE_ENV+=		HTTPDGID=${APACHE_GROUP}
CONFIGURE_ENV+=		XYMONLOGDIR=${XYMONLOGDIR}
CONFIGURE_ENV+=		XYMONVAR=${XYMONVAR:Q}
CONFIGURE_ENV+=		INSTALLROOT=${DESTDIR}
CONFIGURE_ENV+=		INSTALLBINDIR=${XYBINDIR}
CONFIGURE_ENV+=		INSTALLETCDIR=${XYETCDIR}
CONFIGURE_ENV+=		INSTALLEXADIR=${EXAMPLEDIR}
CONFIGURE_ENV+=		INSTALLEXTDIR=${XYEXTDIR}
CONFIGURE_ENV+=		INSTALLTMPDIR=${XYTMPDIR}
CONFIGURE_ENV+=		INSTALLWEBDIR=${XYWEBDIR}
CONFIGURE_ENV+=		INSTALLWWWDIR=${EXAMPLEDIR}/www
CONFIGURE_ENV+=		MANROOT=${PREFIX}/${PKGMANDIR}/

SUBST_CLASSES+=		bashpath
SUBST_FILES.bashpath=	xymond/xymonreports.sh.DIST
SUBST_SED.bashpath=	-e 's,/bin/bash,'${BASH:Q}','
SUBST_STAGE.bashpath=	post-patch

USE_TOOLS+=	awk:run		cat:run		cp:run
USE_TOOLS+=	cut:run		date:run	egrep:run
USE_TOOLS+=	expr:run	find:run	grep:run
USE_TOOLS+=	head:run	id:run		ls:run
USE_TOOLS+=	mv:run		rm:run		sed:run
USE_TOOLS+=	sort:run	tail:run	touch:run
USE_TOOLS+=	tr:run		wc:run		bash:run


MAKE_DIRS+=		${XYMONTOPDIR}
MAKE_DIRS+=		${XYMONHOME}


OWN_DIRS_PERMS+=	${XYEXTDIR} ${XYMONUSER} ${XYMONGROUP} 0755
OWN_DIRS_PERMS+=	${XYMONLOGDIR} ${XYMONUSER} ${XYMONGROUP} 0755
OWN_DIRS_PERMS+=	${XYTMPDIR} ${XYMONUSER} ${XYMONGROUP} 0755

OWN_DIRS_PERMS+=	${XYMONVAR} ${XYMONUSER} ${XYMONGROUP} 0755
VAR_SUBDIRS=		acks data disabled download hist histlogs hostdata rrd
.for dir in ${VAR_SUBDIRS}
OWN_DIRS_PERMS+=	${XYMONVAR}/${dir} ${XYMONUSER} ${XYMONGROUP} 0755
.endfor

OWN_DIRS_PERMS+=	${XYWWWDIR} ${XYMONUSER} ${XYMONGROUP} 0755
WWW_SUBDIRS=		gifs help html menu notes wml
.for dir in ${WWW_SUBDIRS}
OWN_DIRS_PERMS+=	${XYWWWDIR}/${dir} ${XYMONUSER} ${XYMONGROUP} 0755
.endfor
OWN_DIRS_PERMS+=	${XYWWWDIR}/rep ${XYMONUSER} ${APACHE_GROUP} 0755
OWN_DIRS_PERMS+=	${XYWWWDIR}/snap ${XYMONUSER} ${APACHE_GROUP} 0755

OWN_DIRS_PERMS+=	${SECCGIDIR} ${XYMONUSER} ${XYMONGROUP} 0700

# actual config files

CFILES=			alerts.cfg analysis.cfg cgioptions.cfg client-local.cfg
CFILES+=		columndoc.csv columndoc.csv combo.cfg
CFILES+=		graphs.cfg holidays.cfg hosts.cfg protocols.cfg
CFILES+=		rrddefinitions.cfg snmpmibs.cfg tasks.cfg
CFILES+=		xymon-apache.conf xymonmenu.cfg xymonserver.cfg
.for file in ${CFILES}
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${file} ${PKG_SYSCONFDIR.xymon}/${file} ${XYMONUSER} ${XYMONGROUP} 0644
.endfor

CFILES2=		critical.cfg critical.cfg.bak
.for file in ${CFILES2}
CONF_FILES_PERMS+=	${EXAMPLEDIR}/${file} ${PKG_SYSCONFDIR.xymon}/${file} ${XYMONUSER} ${XYMONGROUP} 0664
.endfor

SECCGIFILES=		ackinfo.sh acknowledge.sh criticaleditor.sh
SECCGIFILES+=		enadis.sh useradm.sh
.for file in ${SECCGIFILES}
SPECIAL_PERMS+=		${SECCGIDIR}/${file} ${XYMONUSER} ${XYMONGROUP} 0400
.endfor

MAKE_ENV+=		MAKE=${MAKE_PROGRAM:Q}
MAKE_ENV+=		PKGDIR=${PREFIX}
MAKE_ENV+=		INSTALLROOT=${DESTDIR}
MAKE_ENV+=		PKGBUILD=y
MAKE_ENV+=		RPATH=${COMPILER_RPATH_FLAG}
MAKE_ENV+=		${TOOLS_ENV}

MENUFILES=		b2t-blue.gif b2t-grey.gif t2b-blue.gif t2b-grey.gif
MENUFILES+=		xymonmenu-blue.css xymonmenu-grey.css

post-patch:
	${CP} ${WRKSRC}/build/Makefile.FreeBSD \
	      ${WRKSRC}/build/Makefile.DragonFly

post-install:
.for file in ${MENUFILES}
	chmod 0644 ${DESTDIR}${EXAMPLEDIR}/www/menu/${file}
.endfor

.include "options.mk"
.include "../../databases/rrdtool/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/apache.mk"

.include "../../mk/bsd.pkg.mk"
