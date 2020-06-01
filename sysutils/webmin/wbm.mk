# $NetBSD: wbm.mk,v 1.16 2020/06/01 23:07:27 mef Exp $
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
LICENSE=	modified-bsd

.include "version.mk"

WBM_STD_MODULE?=	YES

.if defined(WBM_MOD_REV) && !empty(WBM_MOD_REV) || !empty(WBM_STD_MODULE:M[Nn][Oo])
PKGNAME?=		wbm-${WBM_NAME}-${WBM_VERSION:S/0$/${WBM_MOD_REV}/}
DISTNAME?=		${WBM_NAME}-${WBM_VERSION}-${WBM_MOD_REV}
MASTER_SITES?=		http://www.webmin.com/updates/
EXTRACT_SUFX?=		.wbm.gz
EXTRACT_OPTS+=		-f tar
WRKSRC?=		${WRKDIR}
WBMSRC=			${WRKDIR}/${WBM_NAME}
.else
PKGNAME=		wbm-${WBM_NAME}-${WBM_VERSION}
DISTNAME=		webmin-${WBM_VERSION}
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=webadmin/}
WBMSRC=			${WRKSRC}/${WBM_NAME}
EXTRACT_ELEMENTS=	${DISTNAME}/${WBM_NAME}
.endif
CATEGORIES+=		sysutils www

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	http://www.webmin.com/standard.html

USE_TOOLS+=	perl:run perl
DEPENDS+=	webmin>=${WBM_VERSION}:../../sysutils/webmin

.for m in ${WBM_DEPEND_MODULES}
DEPENDS+=	wbm-${m}>=${WBM_VERSION}:../../sysutils/wbm-${m}
.endfor

WEBMIN_DIR=	${PREFIX}/share/webmin
WEBMIN_EGDIR=	${PREFIX}/share/examples/webmin
WEBMIN_VARDIR=	${VARBASE}/webmin
WBM_DIR=	${PREFIX}/share/webmin
WBM_EGDIR=	${PREFIX}/share/examples/webmin


PKG_SYSCONFSUBDIR=	webmin
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/${WBM_NAME}			\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
CONF_FILES_PERMS+=	${WBM_EGDIR}/${WBM_NAME}/config			\
			${PKG_SYSCONFDIR}/${WBM_NAME}/config		\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
FILES_SUBST+=		WBM_NAME=${WBM_NAME:Q}
FILES_SUBST+=		WEBMIN_DIR=${WEBMIN_DIR:Q}
FILES_SUBST+=		WEBMIN_VARDIR=${WEBMIN_VARDIR:Q}
BUILD_DEFS+=		VARBASE

INSTALL_TEMPLATES+=	${PKGSRCDIR}/sysutils/webmin/files/wbm-install.tmpl
DEINSTALL_TEMPLATES+=	${PKGSRCDIR}/sysutils/webmin/files/wbm-deinstall.tmpl

# WBM_NAME is the name of the module directory
WBM_NAME?=		${DISTNAME}
WEBMIN_OSTYPE_cmd=	${AWK} '/^os_type=/ {sub("os_type=",""); print}' \
			${WEBMIN_EGDIR}/config
WEBMIN_OSVERSION_cmd=	${AWK} '/^os_version=/ {sub("os_version=",""); print}' \
			${WEBMIN_EGDIR}/config

.PHONY: wbm-configure wbm-build wbm-install

post-patch:
	${FIND} ${WBMSRC} -name "*.pl"   |xargs ${CHMOD} -x
	${FIND} ${WBMSRC} -name "*.html" |xargs ${CHMOD} -x
	${FIND} ${WBMSRC} -name "*.gif"  |xargs ${CHMOD} -x
	${FIND} ${WBMSRC} -name "*.png"  |xargs ${CHMOD} -x

wbm-configure:
	${FIND} ${WBMSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

wbm-build:
	${FIND} ${WBMSRC} -name '*.cgi' -print -o -name '*.pl' -print |	\
	${PERL5} ${WEBMIN_DIR}/perlpath.pl ${PERL5} -

INSTALLATION_DIRS+=	${WBM_DIR} ${WBM_EGDIR}

wbm-install:
	${CP} -R ${WBMSRC} ${DESTDIR}${WBM_DIR}/.
	${PERL5} ${WEBMIN_DIR}/copyconfig.pl				\
		${WEBMIN_OSTYPE_cmd:sh:Q} ${WEBMIN_OSVERSION_cmd:sh:Q:S/^$/''/}\
		${DESTDIR}${WBM_DIR} ${DESTDIR}${WBM_EGDIR} ${WBM_NAME}

do-configure: wbm-configure
do-build: wbm-build
do-install: wbm-install
