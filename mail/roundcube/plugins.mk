# $NetBSD: plugins.mk,v 1.4 2021/09/09 01:11:43 khorben Exp $
#

# plugin's PKGNAME
PKGNAME=	${PHP_PKG_PREFIX}-roundcube-plugin-${PLUGIN}-${RC_VERS}

DEPENDS+=	${PHP_PKG_PREFIX}-roundcube>=${RC_VERS}:../../mail/roundcube

#
# a few parameters
EXTRACT_ELEMENTS?=	${WRKNAME}/${PLUGIN_DIR}
PLUGIN_DIR?=		plugins/${PLUGIN}
CONF_PLUGINS?=		${PLUGIN}

.for f in ${CONF_PLUGINS}
CONF_FILES_PERMS+=	${EGDIR}/plugins/${f}/config.inc.php \
			${PKG_SYSCONFDIR}/${f}.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640
.endfor

do-install:
.for i in ${PLUGIN_DIR}
	cd ${WRKSRC}/${i} && ${FIND} . -type f \! -name "*.orig" -print | \
		${PAX} -rw ${DESTDIR}${PREFIX}/${RCDIR}/${i}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/${i} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/${RCDIR}/${i} -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/${RCDIR}/${i}
.endfor

.include "../../mail/roundcube/Makefile.common"
