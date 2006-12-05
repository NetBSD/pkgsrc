# $NetBSD: Makefile,v 1.52.4.2 2006/12/05 13:48:23 ghen Exp $

DISTNAME=	dspam-3.6.8
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dspam.nuclearelephant.com/
COMMENT=	Extremely scalable, statistical-hybrid anti-spam filter

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

USE_TOOLS+=		perl:run pkg-config
REPLACE_PERL=		src/tools/dspam_train.in			\
			src/tools/dspam_logrotate			\
			webui/cgi-bin/*.cgi webui/cgi-bin/configure.pl.in

PKGCONFIG_OVERRIDE+=	src/dspam.pc.in

SUBST_CLASSES+=		cgi
SUBST_STAGE.cgi=	post-patch
SUBST_FILES.cgi=	webui/cgi-bin/templates/nav_performance.html	    \
			webui/cgi-bin/configure.pl.in			    \
			webui/cgi-bin/dspam.cgi webui/cgi-bin/admin.cgi	    \
			webui/cgi-bin/graph.cgi webui/cgi-bin/admingraph.cgi
SUBST_SED.cgi=		-e "s|auxw|${DSPAM_PSFLAGS}|g"			    \
			-e "s|yourdomain.com|${DSPAM_DOMAIN}|g"		    \
			-e "s|./admins|${PKG_SYSCONFDIR}/cgi-admins|"	    \
			-e "s|configure.pl|${PKG_SYSCONFDIR}/configure.pl|" \
			-e "s|\"\/\";|\"${DSPAM_WWWHOME}\";|" 		    \
			-e "s|\$$FILE = \"./default.prefs\";|\$$FILE = \"${PKG_SYSCONFDIR}/cgi-default.prefs\";|"
SUBST_MESSAGE.cgi=	Fixing paths and default options.

BUILD_DEFS+=		DSPAM_HOME
BUILD_DEFS+=		DSPAM_SIGNATURE_LIFE
BUILD_DEFS+=		DSPAM_USER DSPAM_GROUP
BUILD_DEFS+=		DSPAM_BINMODE
BUILD_DEFS+=		DSPAM_LOGDIR
BUILD_DEFS+=		DSPAM_LOGFILE
BUILD_DEFS+=		DSPAM_DOMAIN
BUILD_DEFS+=		DSPAM_WWWHOME
BUILD_DEFS+=		DSPAM_PIDDIR
BUILD_DEFS+=		DSPAM_WWWUSER DSPAM_WWWGROUP

.include "../../mk/bsd.prefs.mk"

DSPAM_HOME?=		${VARBASE}/dspam
DSPAM_SIGNATURE_LIFE?=	14

DSPAM_BINMODE?=		4511
DSPAM_USER?=		dspam
DSPAM_GROUP?=		dspam
DSPAM_LOGDIR?=		${DSPAM_HOME}/log
DSPAM_LOGFILE?=		${DSPAM_LOGDIR}/dspam.log
DSPAM_DOMAIN?=		yourdomain.com
DSPAM_WWWHOME?=		/dspam
DSPAM_PIDDIR?=		${VARBASE}/run/dspam
DSPAM_WWWUSER?=		${APACHE_USER}
DSPAM_WWWGROUP?=	${APACHE_GROUP}

CONFIGURE_ARGS+=	--with-signature-life=${DSPAM_SIGNATURE_LIFE:Q}
CONFIGURE_ARGS+=	--with-dspam-home=${DSPAM_HOME:Q}			\
			--with-dspam-home-owner=${DSPAM_USER:Q}		\
			--with-dspam-home-group=${DSPAM_GROUP:Q}		\
			--with-dspam-owner=${DSPAM_USER:Q}		\
			--with-dspam-group=${DSPAM_GROUP:Q}		\
			--with-dspam-mode=${DSPAM_BINMODE:Q}		\
			--with-logdir=${DSPAM_LOGDIR:Q}			\
			--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"

DOCDIR=		${PREFIX}/share/doc/dspam
DATADIR=	${PREFIX}/share/dspam
EGDIR=		${PREFIX}/share/examples/dspam

RCD_SCRIPTS=		dspam

PKG_SYSCONFSUBDIR=	dspam

CONF_FILES_PERMS=	${EGDIR}/dspam.conf ${PKG_SYSCONFDIR}/dspam.conf \
			${DSPAM_USER} ${DSPAM_WWWGROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/cgi-admins ${PKG_SYSCONFDIR}/cgi-admins \
			${DSPAM_WWWUSER} ${DSPAM_WWWGROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/cgi-default.prefs \
			${PKG_SYSCONFDIR}/cgi-default.prefs \
			${DSPAM_WWWUSER} ${DSPAM_WWWGROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/configure.pl ${PKG_SYSCONFDIR}/configure.pl \
			${DSPAM_WWWUSER} ${DSPAM_WWWGROUP} 0640

PKG_GROUPS=		${DSPAM_GROUP}
PKG_USERS=		${DSPAM_USER}:${DSPAM_GROUP}
SPECIAL_PERMS=		${PREFIX}/bin/dspam ${DSPAM_USER} ${DSPAM_GROUP} \
			${DSPAM_BINMODE}
OWN_DIRS_PERMS=		${DSPAM_HOME} ${DSPAM_USER} ${DSPAM_WWWGROUP} 0775
OWN_DIRS_PERMS+=	${DSPAM_LOGDIR} ${DSPAM_USER} ${DSPAM_GROUP} 0775
OWN_DIRS_PERMS+=	${DSPAM_PIDDIR} ${DSPAM_USER} ${DSPAM_GROUP} 0770

FILES_SUBST+=		DSPAM_USER=${DSPAM_USER:Q}
FILES_SUBST+=		DSPAM_GROUP=${DSPAM_GROUP:Q}
FILES_SUBST+=		DSPAM_PIDDIR=${DSPAM_PIDDIR:Q}

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	src/dspam.conf.in
SUBST_SED.conf=		-e "s,@dspam_home@,${DSPAM_HOME},g" \
			-e "s,@delivery_agent@,${DSPAM_DELIVERY_AGENT_BIN},g" \
			-e "s|@PREFIX@|${PREFIX}|g" \
			-e "s|@VARBASE@|${VARBASE}|g" \
			-e "s|@DSPAM_PIDDIR@|${DSPAM_PIDDIR}|g"
SUBST_MESSAGE.conf=	Fixing configuration file.

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE.NOTES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCDIR}
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/src/dspam.conf.in ${EGDIR}/dspam.conf
	${INSTALL_DATA} ${WRKSRC}/webui/cgi-bin/admins ${EGDIR}/cgi-admins
	${INSTALL_DATA} ${WRKSRC}/webui/cgi-bin/default.prefs \
		${EGDIR}/cgi-default.prefs
	${INSTALL_DATA} ${WRKSRC}/webui/cgi-bin/configure.pl \
		${EGDIR}/configure.pl

.for d in txt webui/cgi-bin webui/htdocs
	${INSTALL_DATA_DIR} ${DATADIR}/${d}
	cd ${WRKSRC}/${d} && ${PAX} -rwppm '-s|.*/Makefile.*$$||'	\
		'-s|./admins.*$$||' '-s|./default.prefs.*$$||'		\
		'-s|./configure.pl.*$$||' . ${DATADIR}/${d}
.endfor

.for drv in mysql pgsql
.  if !empty(DSPAM_STORAGE_DRIVER:M${drv})
	${INSTALL_DATA_DIR} ${DATADIR}/${drv}
	cd ${WRKSRC}/src/tools.${drv}_drv && \
		${PAX} -rwppm '-s|.*/Makefile.*$$||' . ${DATADIR}/${drv}
.  endif
.endfor

.if !empty(DSPAM_STORAGE_DRIVER:Msqlite*)
	${INSTALL_DATA_DIR} ${DATADIR}/sqlite
	 cd ${WRKSRC}/src/tools.sqlite_drv && \
	 	${PAX} -rwppm '-s|.*/Makefile.*$$||' . ${DATADIR}/sqlite
.endif

.include "../../mk/bsd.pkg.mk"
