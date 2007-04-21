# $NetBSD: wbm.mk,v 1.6 2007/04/21 05:22:57 obache Exp $
#
# Makefile fragment for Webmin modules
#
# Then following variables may be set prior to including this file:
#
# WBM_NAME		Module name.
#
# WBM_STD_MODULE	if "YES", then this package provided as standard
#			module.  defaults to "YES".
#
# WBM_MOD_REV		Updated revision number since the each release.
#			Updated modules are taken from following URL:
#			http://www.webmin.com/updates.html
#
# WBM_DEPEND_MODULES	Depending webmin modules.
#

.include "version.mk"

WBM_STD_MODULE?=YES

.if defined(WBM_MOD_REV) && !empty(WBM_MOD_REV) || !empty(WBM_STD_MODULE:M[Nn][Oo])
PKGNAME?=	wbm-${WBM_NAME}-${WBM_VERSION:S/0$/${WBM_MOD_REV}/}
DISTNAME?=	${WBM_NAME}-${WBM_VERSION}-${WBM_MOD_REV}
MASTER_SITES?=	http://www.webmin.com/updates/
EXTRACT_SUFX?=	.wbm.gz
EXTRACT_OPTS+=	-f tar
WRKSRC?=	${WRKDIR}
WBMSRC=		${WRKDIR}/${WBM_NAME}
.else
PKGNAME=	wbm-${WBM_NAME}-${WBM_VERSION}
DISTNAME=	webmin-${WBM_VERSION}
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=webadmin/}
WBMSRC=		${WRKSRC}/${WBM_NAME}
.endif
CATEGORIES+=	sysutils www

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	http://www.webmin.com/standard.html

USE_TOOLS+=	perl:run
DEPENDS+=	webmin>=${WBM_VERSION}:../../sysutils/webmin

.for m in ${WBM_DEPEND_MODULES}
DEPENDS+=	wbm-${m}>=${WBM_VERSION}:../../sysutils/wbm-${m}
.endfor

EVAL_PREFIX+=	PREFIX.webmin=webmin
WEBMIN_DIR=	${PREFIX.webmin}/share/webmin
WEBMIN_EGDIR=	${PREFIX.webmin}/share/examples/webmin
WEBMIN_VARDIR=	${VARBASE}/webmin
WBM_DIR=	${PREFIX}/share/webmin
WBM_EGDIR=	${PREFIX}/share/examples/webmin


PKG_SYSCONFSUBDIR=	webmin
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/${WBM_NAME}			\
			${ROOT_USER} ${ROOT_GROUP} 0700
CONF_FILES_PERMS+=	${WBM_EGDIR}/${WBM_NAME}/config			\
			${PKG_SYSCONFDIR}/${WBM_NAME}/config		\
			${ROOT_USER} ${ROOT_GROUP} 0600
FILES_SUBST+=		WBM_NAME=${WBM_NAME:Q}
FILES_SUBST+=		WEBMIN_DIR=${WEBMIN_DIR:Q}
FILES_SUBST+=		WEBMIN_VARDIR=${WEBMIN_VARDIR:Q}
BUILD_DEFS+=		VARBASE

DEINSTALL_TEMPLATES+=	${PKGSRCDIR}/sysutils/webmin/files/wbm-deinstall.tmpl

# WBM_NAME is the name of the module directory
WBM_NAME?=		${DISTNAME}
WEBMIN_OSTYPE_cmd=	${AWK} '/^os_type=/ {sub("os_type=",""); print}' \
			${WEBMIN_EGDIR}/config
WEBMIN_OSVERSION_cmd=	${AWK} '/^os_version=/ {sub("os_version=",""); print}' \
			${WEBMIN_EGDIR}/config

.PHONY: wbm-configure wbm-build wbm-install

wbm-configure:
	${FIND} ${WBMSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

wbm-build:
	${FIND} ${WBMSRC} -name '*.cgi' -print -o -name '*.pl' -print |	\
	${PERL5} ${WEBMIN_DIR}/perlpath.pl ${PERL5} -

wbm-install:
	${CP} -R ${WBMSRC} ${WBM_DIR}/.
	${PERL5} ${WEBMIN_DIR}/copyconfig.pl				\
		${WEBMIN_OSTYPE_cmd:sh:Q} ${WEBMIN_OSVERSION_cmd:sh:Q}	\
		${WBM_DIR} ${WBM_EGDIR} ${WBM_NAME}

do-configure: wbm-configure
do-build: wbm-build
do-install: wbm-install
