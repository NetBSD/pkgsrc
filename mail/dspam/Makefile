# $NetBSD: Makefile,v 1.119 2024/05/29 16:33:20 adam Exp $

DISTNAME=	dspam-3.10.2
PKGREVISION=	41
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dspam/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dspam.sourceforge.net/
COMMENT=	Extremely scalable, statistical-hybrid anti-spam filter

MAKE_JOBS_SAFE=	no

LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

USE_TOOLS+=		pax perl:run pkg-config
REPLACE_PERL=		src/tools/dspam_train.in
REPLACE_PERL+=		src/tools/dspam_logrotate
REPLACE_PERL+=		src/tools/dspam_notify.in
REPLACE_PERL+=		webui/cgi-bin/*.cgi webui/cgi-bin/configure.pl.in
REPLACE_PERL+=		webui/cgi-bin/htmlize.pl
REPLACE_PERL+=		webui/cgi-bin/templates/strings.pl
REPLACE_PERL+=		webui/cgi-bin/templates/*/strings.pl

PKGCONFIG_OVERRIDE+=	src/dspam.pc.in

SUBST_CLASSES+=		cgi
SUBST_STAGE.cgi=	pre-configure
SUBST_FILES.cgi+=	webui/cgi-bin/configure.pl.in
SUBST_FILES.cgi+=	webui/cgi-bin/dspam.cgi webui/cgi-bin/admin.cgi
SUBST_FILES.cgi+=	webui/cgi-bin/graph.cgi webui/cgi-bin/admingraph.cgi
SUBST_SED.cgi=		-e "s|auxw|${DSPAM_PSFLAGS}|g"
SUBST_SED.cgi+=		-e "s|yourdomain.com|${DSPAM_DOMAIN}|g"
SUBST_SED.cgi+=		-e "s|./admins|${PKG_SYSCONFDIR}/cgi-admins|"
SUBST_SED.cgi+=		-e "s|configure.pl|${PKG_SYSCONFDIR}/configure.pl|"
SUBST_SED.cgi+=		-e "s|\"\\/\";|\"${DSPAM_WWWHOME}\";|"
SUBST_SED.cgi+=		-e "s|\$$FILE = \"./default.prefs\";|\$$FILE = \"${PKG_SYSCONFDIR}/cgi-default.prefs\";|"
SUBST_MESSAGE.cgi=	Fixing paths and default options.

BUILD_DEFS+=		DSPAM_HOME VARBASE
BUILD_DEFS+=		DSPAM_BINMODE
BUILD_DEFS+=		DSPAM_LOGDIR
BUILD_DEFS+=		DSPAM_LOGFILE
BUILD_DEFS+=		DSPAM_DOMAIN
BUILD_DEFS+=		DSPAM_WWWHOME
BUILD_DEFS+=		DSPAM_PIDDIR
BUILD_DEFS+=		APACHE_USER
BUILD_DEFS+=		APACHE_GROUP

.include "../../mk/bsd.prefs.mk"

# Can be removed after 2020Q4.
.if defined(DSPAM_SIGNATURE_LIFE)
PKG_FAIL_REASON+=	"DSPAM_SIGNATURE_LIFE is not used anymore."
.endif

DSPAM_HOME?=		${VARBASE}/dspam

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

PKG_GROUPS_VARS+=	DSPAM_GROUP DSPAM_WWWGROUP
PKG_USERS_VARS+=	DSPAM_USER DSPAM_WWWUSER

CONFIGURE_ARGS+=	--with-dspam-home=${DSPAM_HOME}			\
			--with-dspam-home-owner=${DSPAM_USER}		\
			--with-dspam-home-group=${DSPAM_GROUP}		\
			--with-dspam-owner=${DSPAM_USER}		\
			--with-dspam-group=${DSPAM_GROUP}		\
			--with-dspam-mode=${DSPAM_BINMODE}		\
			--with-logdir=${DSPAM_LOGDIR}			\
			--sysconfdir=${PKG_SYSCONFDIR}

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

FILES_SUBST+=		DSPAM_USER=${DSPAM_USER}
FILES_SUBST+=		DSPAM_GROUP=${DSPAM_GROUP}
FILES_SUBST+=		DSPAM_HOME=${DSPAM_HOME}
FILES_SUBST+=		DSPAM_PIDDIR=${DSPAM_PIDDIR}

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	src/dspam.conf.in
SUBST_SED.conf=		-e "s|@dspam_home@|${DSPAM_HOME}|g"
SUBST_SED.conf+=	-e "s|@delivery_agent@|${DSPAM_DELIVERY_AGENT_BIN}|g"
SUBST_VARS.conf=	PREFIX
SUBST_VARS.conf+=	VARBASE
SUBST_VARS.conf+=	DSPAM_PIDDIR
SUBST_MESSAGE.conf=	Fixing configuration file.

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

INSTALLATION_DIRS+=	${DOCDIR} ${DATADIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE.NOTES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/src/dspam.conf.in ${DESTDIR}${EGDIR}/dspam.conf
	${INSTALL_DATA} ${WRKSRC}/webui/cgi-bin/admins ${DESTDIR}${EGDIR}/cgi-admins
	${INSTALL_DATA} ${WRKSRC}/webui/cgi-bin/default.prefs \
	    ${DESTDIR}${EGDIR}/cgi-default.prefs
	${INSTALL_DATA} ${WRKSRC}/webui/cgi-bin/configure.pl \
	    ${DESTDIR}${EGDIR}/configure.pl

.for d in txt webui/cgi-bin webui/htdocs
	${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}/${d}
	cd ${WRKSRC}/${d} && pax -rwppm '-s|.*/Makefile.*$$||'	\
		'-s|./admins.*$$||' '-s|./default.prefs.*$$||'		\
		'-s|./configure.pl.*$$||' . ${DESTDIR}${DATADIR}/${d}
.endfor

.for drv in mysql pgsql
.  if !empty(DSPAM_STORAGE_DRIVER:M${drv})
	${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}/${drv}
	cd ${WRKSRC}/src/tools.${drv}_drv && \
		pax -rwpm ./*.sql ${DESTDIR}${DATADIR}/${drv}
.  endif
.endfor

.if !empty(DSPAM_STORAGE_DRIVER:Msqlite*)
	${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}/sqlite
	 cd ${WRKSRC}/src/tools.sqlite_drv && \
	 	pax -rwpm '-s|.*/Makefile.*$$||' . ${DESTDIR}${DATADIR}/sqlite
.endif

	${CHMOD} ${SHAREMODE} ${DESTDIR}${DATADIR}/webui/cgi-bin/*.txt
	${CHMOD} ${SHAREMODE} ${DESTDIR}${DATADIR}/webui/cgi-bin/templates/*.html
	${CHMOD} ${SHAREMODE} ${DESTDIR}${DATADIR}/webui/htdocs/*.css
	${CHMOD} ${SHAREMODE} ${DESTDIR}${DATADIR}/webui/htdocs/*.gif

.include "../../mk/bsd.pkg.mk"
