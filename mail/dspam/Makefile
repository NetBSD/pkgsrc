# $NetBSD: Makefile,v 1.22 2005/02/20 00:05:51 xtraeme Exp $

DISTNAME=	dspam-3.2.7
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nuclearelephant.com/projects/dspam/
COMMENT=	Extremely scalable, statistical-hybrid anti-spam filter

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

USE_PERL5=		yes
REPLACE_PERL=		tools/dspam_genaliases.in			\
			tools/dspam_corpus.in				\
			cgi/*.cgi cgi/configure.pl.in

PKGCONFIG_OVERRIDE+=	dspam.pc.in

SUBST_CLASSES+=		cgi
SUBST_STAGE.cgi=	post-patch
SUBST_FILES.cgi=	cgi/dspam.cgi cgi/admin.cgi \
			cgi/templates/nav_performance.html
SUBST_SED.cgi=		-e "s|/usr/local/bin/dspam|${PREFIX}/bin/dspam|g" \
			-e "s|/var/dspam|${DSPAM_HOME}|g"		\
			-e "s|/usr/local|${PREFIX}|g"			\
			-e "s|-deaf|${DSPAM_PSFLAGS}|g"			\
			-e "s|yourdomain.com|${DSPAM_DOMAIN}|g"
SUBST_MESSAGE.cgi=	"Fixing paths and default options."

BUILD_DEFS+=		DSPAM_HOME
BUILD_DEFS+=		DSPAM_SIGNATURE_LIFE
BUILD_DEFS+=		DSPAM_USER DSPAM_GROUP
BUILD_DEFS+=		DSPAM_BINMODE
BUILD_DEFS+=		DSPAM_LOGDIR
BUILD_DEFS+=		DSPAM_DOMAIN

.include "../../mk/bsd.prefs.mk"

DSPAM_HOME?=		${VARBASE}/dspam
DSPAM_SIGNATURE_LIFE?=	14

DSPAM_BINMODE?=		4511
DSPAM_USER?=		dspam
DSPAM_GROUP?=		dspam
DSPAM_LOGDIR?=		${DSPAM_HOME}/log
DSPAM_DOMAIN?=		yourdomain.com

CONFIGURE_ARGS+=	--with-signature-life=${DSPAM_SIGNATURE_LIFE}
CONFIGURE_ARGS+=	--with-dspam-home=${DSPAM_HOME}			\
			--with-dspam-home-owner=${DSPAM_USER}		\
			--with-dspam-home-group=${DSPAM_GROUP}		\
			--with-dspam-owner=${DSPAM_USER}		\
			--with-dspam-group=${DSPAM_GROUP}		\
			--with-dspam-mode=${DSPAM_BINMODE}		\
			--with-logdir=${DSPAM_LOGDIR}

.include "options.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

DOCDIR=		${PREFIX}/share/doc/dspam
DATADIR=	${PREFIX}/share/dspam
EGDIR=		${PREFIX}/share/examples/dspam

USE_PKGINSTALL=		yes
CONF_FILES_PERMS=	${EGDIR}/dspam.conf ${PKG_SYSCONFDIR}/dspam.conf \
			${BINOWN} ${DSPAM_GROUP} 0640

PKG_GROUPS=		${DSPAM_GROUP}
PKG_USERS=		${DSPAM_USER}:${DSPAM_GROUP}
SPECIAL_PERMS=		${PREFIX}/bin/dspam ${DSPAM_USER} ${DSPAM_GROUP} \
			${DSPAM_BINMODE}
OWN_DIRS_PERMS=		${DSPAM_HOME} ${DSPAM_USER} ${DSPAM_GROUP} 0775
OWN_DIRS_PERMS+=	${DSPAM_LOGDIR} ${DSPAM_USER} ${DSPAM_GROUP} 0775

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	dspam.conf.in
SUBST_SED.conf=		-e "s,@dspam_home@,${DSPAM_HOME},g" \
			-e "s,@delivery_agent@,${DSPAM_DELIVERY_AGENT_BIN},g"
SUBST_MESSAGE.conf=	"Fixing configuration file."

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE.NOTES ${DOCDIR}
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dspam.conf.in ${EGDIR}/dspam.conf
.for d in txt cgi
	${INSTALL_DATA_DIR} ${DATADIR}/${d}
	cd ${WRKSRC}/${d} && ${PAX} -rwppm '-s|.*/Makefile.*$$||'	\
		. ${DATADIR}/${d}
.endfor
	${RM} ${DATADIR}/cgi/configure.pl.in
.undef d
.for drv in mysql pgsql sqlite
.  if !empty(DSPAM_STORAGE_DRIVER:M${drv})
	${INSTALL_DATA_DIR} ${DATADIR}/${drv}
	cd ${WRKSRC}/tools.${drv}_drv && ${PAX} -rwppm '-s|.*/Makefile.*$$||' \
		. ${DATADIR}/${drv}
.  endif
.endfor
.undef drv

.include "../../mk/bsd.pkg.mk"
