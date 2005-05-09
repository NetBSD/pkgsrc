# $NetBSD: Makefile,v 1.31 2005/05/09 11:10:54 xtraeme Exp $

DISTNAME=	dspam-3.4.6
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nuclearelephant.com/projects/dspam/
COMMENT=	Extremely scalable, statistical-hybrid anti-spam filter

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

USE_PERL5=		yes
REPLACE_PERL=		tools/dspam_genaliases.in			\
			tools/dspam_corpus.in				\
			cgi/*.cgi cgi/configure.pl.in

PKGCONFIG_OVERRIDE+=	dspam.pc.in

SUBST_CLASSES+=		cgi cgi2
SUBST_STAGE.cgi=	post-patch
SUBST_FILES.cgi=	cgi/dspam.cgi cgi/admin.cgi		\
			cgi/templates/nav_performance.html	\
			cgi/configure.pl.in
SUBST_SED.cgi=		-e "s|/usr/local/bin/dspam|${PREFIX}/bin/dspam|g"	\
			-e "s|/var/dspam|${DSPAM_HOME}|g"		\
			-e "s|/usr/local|${PREFIX}|g"			\
			-e "s|-deaf|${DSPAM_PSFLAGS}|g"			\
			-e "s|yourdomain.com|${DSPAM_DOMAIN}|g"
SUBST_MESSAGE.cgi=	"Fixing paths and default options."
SUBST_STAGE.cgi2=	post-patch
SUBST_FILES.cgi2=	cgi/dspam.cgi cgi/admin.cgi cgi/admingraph.cgi	\
			cgi/graph.cgi
SUBST_SED.cgi2=		-e "s|./admins|${PKG_SYSCONFDIR}/cgi-admins|"	\
	-e "s|\$$FILE = \"./default.prefs\";|\$$FILE = \"${PKG_SYSCONFDIR}/cgi-default.prefs\";|" \
	-e "s|configure.pl|${PKG_SYSCONFDIR}/configure.pl|"

BUILD_DEFS+=		DSPAM_HOME
BUILD_DEFS+=		DSPAM_SIGNATURE_LIFE
BUILD_DEFS+=		DSPAM_USER DSPAM_GROUP
BUILD_DEFS+=		DSPAM_BINMODE
BUILD_DEFS+=		DSPAM_LOGDIR
BUILD_DEFS+=		DSPAM_DOMAIN
BUILD_DEFS+=		DSPAM_PIDDIR

.include "../../mk/bsd.prefs.mk"

DSPAM_HOME?=		${VARBASE}/dspam
DSPAM_SIGNATURE_LIFE?=	14

DSPAM_BINMODE?=		4511
DSPAM_USER?=		dspam
DSPAM_GROUP?=		dspam
DSPAM_LOGDIR?=		${DSPAM_HOME}/log
DSPAM_DOMAIN?=		yourdomain.com
DSPAM_PIDDIR?=		${VARBASE}/run/dspam

CONFIGURE_ARGS+=	--with-signature-life=${DSPAM_SIGNATURE_LIFE}
CONFIGURE_ARGS+=	--with-dspam-home=${DSPAM_HOME}			\
			--with-dspam-home-owner=${DSPAM_USER}		\
			--with-dspam-home-group=${DSPAM_GROUP}		\
			--with-dspam-owner=${DSPAM_USER}		\
			--with-dspam-group=${DSPAM_GROUP}		\
			--with-dspam-mode=${DSPAM_BINMODE}		\
			--with-logdir=${DSPAM_LOGDIR}			\
			--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

DOCDIR=		${PREFIX}/share/doc/dspam
DATADIR=	${PREFIX}/share/dspam
EGDIR=		${PREFIX}/share/examples/dspam

USE_PKGINSTALL=		yes
RCD_SCRIPTS=		dspam

PKG_SYSCONFSUBDIR=	dspam

CONF_FILES_PERMS=	${EGDIR}/dspam.conf ${PKG_SYSCONFDIR}/dspam.conf \
			${BINOWN} ${DSPAM_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/cgi-admins ${PKG_SYSCONFDIR}/cgi-admins \
			${APACHE_USER} ${APACHE_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/cgi-default.prefs \
			${PKG_SYSCONFDIR}/cgi-default.prefs \
			${APACHE_USER} ${APACHE_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/configure.pl ${PKG_SYSCONFDIR}/configure.pl \
			${APACHE_USER} ${APACHE_GROUP} 0640

PKG_GROUPS=		${DSPAM_GROUP}
PKG_USERS=		${DSPAM_USER}:${DSPAM_GROUP}
SPECIAL_PERMS=		${PREFIX}/bin/dspam ${DSPAM_USER} ${DSPAM_GROUP} \
			${DSPAM_BINMODE}
OWN_DIRS_PERMS=		${DSPAM_HOME} ${DSPAM_USER} ${APACHE_GROUP} 0775
OWN_DIRS_PERMS+=	${DSPAM_LOGDIR} ${DSPAM_USER} ${DSPAM_GROUP} 0775
OWN_DIRS_PERMS+=	${DSPAM_PIDDIR} ${DSPAM_USER} ${DSPAM_GROUP} 0700

FILES_SUBST+=		DSPAM_USER=${DSPAM_USER}
FILES_SUBST+=		DSPAM_GROUP=${DSPAM_GROUP}
FILES_SUBST+=		DSPAM_PIDDIR=${DSPAM_PIDDIR}

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	src/dspam.conf.in
SUBST_SED.conf=		-e "s,@dspam_home@,${DSPAM_HOME},g" \
			-e "s,@delivery_agent@,${DSPAM_DELIVERY_AGENT_BIN},g"
SUBST_MESSAGE.conf=	"Fixing configuration file."

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE.NOTES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCDIR}
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/src/dspam.conf.in ${EGDIR}/dspam.conf
	${INSTALL_DATA} ${WRKSRC}/cgi/admins ${EGDIR}/cgi-admins
	${INSTALL_DATA} ${WRKSRC}/cgi/default.prefs ${EGDIR}/cgi-default.prefs
	${INSTALL_DATA} ${WRKSRC}/cgi/configure.pl ${EGDIR}/configure.pl

.for d in txt cgi
	${INSTALL_DATA_DIR} ${DATADIR}/${d}
	cd ${WRKSRC}/${d} && ${PAX} -rwppm '-s|.*/Makefile.*$$||'	\
		'-s|./admins.*$$||' '-s|./default.prefs.*$$||'		\
		'-s|./configure.pl.*$$||' . ${DATADIR}/${d}
.endfor
.undef d
.for drv in mysql pgsql
.  if !empty(DSPAM_STORAGE_DRIVER:M${drv})
	${INSTALL_DATA_DIR} ${DATADIR}/${drv}
	cd ${WRKSRC}/src/tools.${drv}_drv && \
		${PAX} -rwppm '-s|.*/Makefile.*$$||' . ${DATADIR}/${drv}
.  endif
.endfor
.undef drv
.if !empty(DSPAM_STORAGE_DRIVER:Msqlite*)
	${INSTALL_DATA_DIR} ${DATADIR}/sqlite
	 cd ${WRKSRC}/src/tools.sqlite_drv && \
	 	${PAX} -rwppm '-s|.*/Makefile.*$$||' . ${DATADIR}/sqlite
.endif

.include "../../mk/bsd.pkg.mk"
