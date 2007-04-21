# $NetBSD: Makefile,v 1.20 2007/04/21 05:22:57 obache Exp $

.include "version.mk"

DISTNAME=	webmin-${WBM_VERSION}
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=webadmin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.webmin.com/
COMMENT=	Perl web server and CGI for Unix system administration

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

.include "../../security/openssl/buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/acl_config-dragonfly ${WRKSRC}/acl/config-dragonfly
	${CP} ${FILESDIR}/init_config-dragonfly ${WRKSRC}/init/config-dragonfly
	${CP} ${FILESDIR}/man_config-dragonfly ${WRKSRC}/man/config-dragonfly
	${CP} ${FILESDIR}/proc_config-dragonfly ${WRKSRC}/proc/config-dragonfly

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
	${SED}	-e "s,@WEBMIN_EGDIR@,${WEBMIN_EGDIR},g"			\
		-e "s,@WEBMIN_VARDIR@,${WEBMIN_VARDIR},g"		\
		-e "s,@PERL5@,"${PERL5:Q}",g"				\
		${FILESDIR}/setup-pre.sh > ${WRKSRC}/setup-pre.sh
	cd ${WRKSRC}; for file in acl/config acl/config-*; do		\
		${SED} -e "s,^ssleay=.*,ssleay=${SSLBASE}/bin/openssl,"	\
			"$$file" > "$$file.new";			\
		${MV} -f "$$file.new" "$$file";				\
	done
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

# Fix up the path to the config directory in the installed example config
# files.
#
do-install:
	${SH} ${WRKSRC}/setup.sh ${WEBMIN_DIR}
	${SED}	-e "/^env_WEBMIN_CONFIG=/s,${WEBMIN_EGDIR},${WEBMIN_ETCDIR}," \
		-e "/^logout=/s,${WEBMIN_EGDIR},${WEBMIN_ETCDIR},"	\
		-e "/^userfile=/s,${WEBMIN_EGDIR},${WEBMIN_ETCDIR},"	\
		-e "/^keyfile=/s,${WEBMIN_EGDIR},${WEBMIN_ETCDIR},"	\
		${WEBMIN_EGDIR}/miniserv.conf > ${WRKDIR}/miniserv.conf
	for file in reload start stop; do				\
		${SED}	-e "s,${WEBMIN_EGDIR}/miniserv.conf,${WEBMIN_ETCDIR}/miniserv.conf," \
			${WEBMIN_EGDIR}/$$file > ${WRKDIR}/$$file;	\
	done
	cd ${WEBMIN_EGDIR} && ${RM} -f miniserv.conf reload start stop
	for file in miniserv.conf; do					\
		${INSTALL_DATA} ${WRKDIR}/$$file ${WEBMIN_EGDIR}/$$file; \
		${RM} -f ${WRKDIR}/$$file;				\
	done
	for file in reload start stop; do				\
		${INSTALL_SCRIPT} ${WRKDIR}/$$file ${WEBMIN_EGDIR}/$$file; \
		${RM} -f ${WRKDIR}/$$file;				\
	done
	${RM} -f ${WEBMIN_EGDIR}/miniserv.pem ${WEBMIN_EGDIR}/module.infos.cache
	cd ${WEBMIN_DIR} && ${CHMOD} 0400 setup.pl setup.sh setup-pre.sh

.include "../../mk/bsd.pkg.mk"
