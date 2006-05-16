# $NetBSD: wbm.mk,v 1.3 2006/05/16 16:38:06 jlam Exp $
#
# Makefile fragment for Webmin modules

PKGNAME?=	wbm-${DISTNAME}
CATEGORIES+=	sysutils www
MASTER_SITES?=	http://download.webmin.com/download/modules/
EXTRACT_SUFX?=	.wbm.gz
EXTRACT_OPTS+=	-f tar

MAINTAINER?=	pkgsrc-users@NetBSD.org

USE_TOOLS+=	perl:run
DEPENDS+=	webmin>=1.270:../../sysutils/webmin

EVAL_PREFIX+=	PREFIX.webmin=webmin
WEBMIN_DIR=	${PREFIX.webmin}/share/webmin
WEBMIN_EGDIR=	${PREFIX.webmin}/share/examples/webmin
WBM_DIR=	${PREFIX}/share/webmin
WBM_EGDIR=	${PREFIX}/share/examples/webmin

WRKSRC?=	${WRKDIR}/${WBMNAME}

PKG_SYSCONFSUBDIR=	webmin
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/${WBMNAME}			\
			${ROOT_USER} ${ROOT_GROUP} 0700
CONF_FILES_PERMS+=	${WBM_EGDIR}/${WBMNAME}/config			\
			${PKG_SYSCONFDIR}/${WBMNAME}/config		\
			${ROOT_USER} ${ROOT_GROUP} 0600

# WBMNAME is the name of the module directory
WBMNAME?=		${DISTNAME}
WEBMIN_OSTYPE_cmd=	${AWK} '/^os_type=/ {sub("os_type=",""); print}' \
			${WEBMIN_EGDIR}/config
WEBMIN_OSVERSION_cmd=	${AWK} '/^os_version=/ {sub("os_version=",""); print}' \
			${WEBMIN_EGDIR}/config

.PHONY: wbm-configure wbm-build wbm-install

wbm-configure:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

wbm-build:
	${FIND} ${WRKSRC} -name '*.cgi' -print -o -name '*.pl' -print |	\
	${PERL5} ${WEBMIN_DIR}/perlpath.pl ${PERL5} -

wbm-install:
	${CP} -R ${WRKSRC} ${WBM_DIR}/.
	${PERL5} ${WEBMIN_DIR}/copyconfig.pl				\
		${WEBMIN_OSTYPE_cmd:sh:Q} ${WEBMIN_OSVERSION_cmd:sh:Q}	\
		${WBM_DIR}/${WBM_NAME} ${WBM_EGDIR} ${WBMNAME}

do-configure: wbm-configure
do-build: wbm-build
do-install: wbm-install
