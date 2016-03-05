# $NetBSD: Makefile,v 1.41 2016/03/05 11:29:32 jperkin Exp $

.include "version.mk"

DISTNAME=	webmin-${WBM_VERSION}
#KGREVISION=	5
PKGREVISION=	6
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=webadmin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.webmin.com/
COMMENT=	Perl web server and CGI for Unix system administration
LICENSE=        modified-bsd

DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# empty
NO_BUILD=	yes

USE_TOOLS+=	perl:run

WEBMIN_DIR=		${PREFIX}/share/webmin
WEBMIN_EGDIR=		${PREFIX}/share/examples/webmin
WEBMIN_ETCDIR=		${PKG_SYSCONFDIR}
WEBMIN_VARDIR=		${VARBASE}/webmin
FILES_SUBST+=		WEBMIN_DIR=${WEBMIN_DIR:Q}
FILES_SUBST+=		WEBMIN_EGDIR=${WEBMIN_EGDIR:Q}
FILES_SUBST+=		WEBMIN_ETCDIR=${WEBMIN_ETCDIR:Q}
FILES_SUBST+=		WEBMIN_MINIMAL_MODULES=${WEBMIN_MINIMAL_MODULES:Q}
FILES_SUBST+=		WEBMIN_VARDIR=${WEBMIN_VARDIR:Q}
MESSAGE_SUBST+=		WEBMIN_DIR=${WEBMIN_DIR:Q}
BUILD_DEFS+=		VARBASE

WEBMIN_MINIMAL_MODULES=	acl cron init inittab man proc servers webmin webminlog

PKG_SYSCONFSUBDIR=	webmin
OWN_DIRS_PERMS+=	${WEBMIN_VARDIR} ${ROOT_USER} ${ROOT_GROUP} 0700
.for f in		config install-dir perl-path var-path version
CONF_FILES+=		${WEBMIN_EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.for m in		${WEBMIN_MINIMAL_MODULES}
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/${m}				\
			${ROOT_USER} ${ROOT_GROUP} 0700
CONF_FILES_PERMS+=	${WEBMIN_EGDIR}/${m}/config			\
			${PKG_SYSCONFDIR}/${m}/config			\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
.for f in		miniserv.pem
CONF_FILES_PERMS+=	${WEBMIN_DIR}/${f} ${PKG_SYSCONFDIR}/${f}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
.for f in		miniserv.conf miniserv.users webmin.acl
CONF_FILES_PERMS+=	${WEBMIN_EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
.for f in		reload restart start stop
CONF_FILES_PERMS+=	${WEBMIN_EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}	\
			${ROOT_USER} ${ROOT_GROUP} 0755
.endfor
RCD_SCRIPTS=		webmin

CHECK_INTERPRETER_SKIP+=	share/webmin/webmin-gentoo-init

ALL_ENV+=	tempdir=${WRKDIR}/.tmp

.include "../../security/openssl/buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/acl_config-dragonfly ${WRKSRC}/acl/config-dragonfly
	${CP} ${FILESDIR}/init_config-dragonfly ${WRKSRC}/init/config-dragonfly
	${CP} ${FILESDIR}/man_config-dragonfly ${WRKSRC}/man/config-dragonfly
	${CP} ${FILESDIR}/proc_config-dragonfly ${WRKSRC}/proc/config-dragonfly
	${RM} -r ${WRKSRC}/acl/Authen-SolarisRBAC-0.1*

pre-configure:
	cd ${WRKSRC} &&							\
	ptn="@"`${ECHO} ${WEBMIN_MINIMAL_MODULES}|sed -e 's/ /@/g'`"@" &&	\
	for m in `${ECHO} */module.info | sed -e 's/\/module.info//g'`; do \
		case $${ptn} in						\
		*@$${m}@*) ;;						\
		*)	rm -rf $${m} ;;					\
		esac;							\
	done &&								\
	for t in `${ECHO} */theme.info | sed -e 's/\/theme.info//g'`; do\
		rm -rf $${t};						\
	done &&								\
	touch ${WRKSRC}/minimal-install

do-configure:
	sed	-e "s,@WEBMIN_EGDIR@,${DESTDIR}${WEBMIN_EGDIR},g"	\
		-e "s,@WEBMIN_VARDIR@,${DESTDIR}${WEBMIN_VARDIR},g"	\
		-e "s,@PERL5@,"${PERL5:Q}",g"				\
		${FILESDIR}/setup-pre.sh > ${WRKSRC}/setup-pre.sh
	cd ${WRKSRC}; for file in acl/config acl/config-*; do		\
		sed -e "s,^ssleay=.*,ssleay=${SSLBASE}/bin/openssl,"	\
			"$$file" > "$$file.new";			\
		${MV} -f "$$file.new" "$$file";				\
	done
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

# Fix up the path to the config directory in the installed example config
# files.
#
do-install:
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${SH} ${WRKSRC}/setup.sh ${DESTDIR}${WEBMIN_DIR}
	sed	-e "/^env_WEBMIN_CONFIG=/s,${DESTDIR}${WEBMIN_EGDIR},${WEBMIN_ETCDIR}," \
		-e "/^logout=/s,${DESTDIR}${WEBMIN_EGDIR},${WEBMIN_ETCDIR},"	\
		-e "/^userfile=/s,${DESTDIR}${WEBMIN_EGDIR},${WEBMIN_ETCDIR},"	\
		-e "/^keyfile=/s,${DESTDIR}${WEBMIN_EGDIR},${WEBMIN_ETCDIR},"	\
		-e "s,${DESTDIR},,g"	\
		${DESTDIR}${WEBMIN_EGDIR}/miniserv.conf > ${WRKDIR}/miniserv.conf
	sed	-e "s,${DESTDIR},,g"	\
		${DESTDIR}${WEBMIN_DIR}/setup-pre.sh > ${WRKDIR}/setup-pre.sh
	for file in install-dir reload restart start stop var-path; do	\
		sed	-e "s,${DESTDIR}${WEBMIN_EGDIR}/miniserv.conf,${WEBMIN_ETCDIR}/miniserv.conf," \
			-e "s,${DESTDIR},,g"	\
			${DESTDIR}${WEBMIN_EGDIR}/$$file > ${WRKDIR}/$$file; \
	done
	cd ${DESTDIR}${WEBMIN_EGDIR} && ${RM} -f miniserv.conf install-dir reload restart start stop var-path
	for file in miniserv.conf; do					\
		${INSTALL_DATA} ${WRKDIR}/$$file			\
				    ${DESTDIR}${WEBMIN_EGDIR}/$$file;	\
		${RM} -f ${WRKDIR}/$$file;				\
	done
	for file in setup-pre.sh; do					\
		${INSTALL_SCRIPT} ${WRKDIR}/$$file			\
				    ${DESTDIR}${WEBMIN_DIR}/$$file;	\
		${RM} -f ${WRKDIR}/$$file;				\
	done
	for file in install-dir reload restart start stop var-path; do	\
		${INSTALL_SCRIPT} ${WRKDIR}/$$file		    	\
				    ${DESTDIR}${WEBMIN_EGDIR}/$$file;	\
		${RM} -f ${WRKDIR}/$$file;				\
	done
	${RM} -f ${DESTDIR}${WEBMIN_EGDIR}/miniserv.pem			\
			    ${DESTDIR}${WEBMIN_EGDIR}/module.infos.cache
	cd ${DESTDIR}${WEBMIN_DIR} &&					\
				${CHMOD} 0400 setup.pl setup.sh setup-pre.sh

.include "../../mk/bsd.pkg.mk"
