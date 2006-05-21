# $NetBSD: Makefile,v 1.23 2006/05/21 16:08:32 rillig Exp $
#

DISTNAME=	i2cbd-2.0_BETA5
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.draga.com/~jwise/i2cb/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.draga.com/~jwise/i2cb/
COMMENT=	Next generation Internet Citizens Band chat server

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		ICBD_OWNER
ICBD_OWNER?=		${ROOT_USER}
PLIST_SUBST+=		ICBD_OWNER=${ICBD_OWNER:Q}

PKG_SYSCONFSUBDIR=	icbd
EGDIR=			${PREFIX}/share/examples/i2cbd
EGFILES=		motd icbd_help icbd.deny news.1
CONF_FILES_PERMS=	# empty
.for f in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${f:Q} ${PKG_SYSCONFDIR}/${f:Q} \
			${ICBD_OWNER} ${ROOT_GROUP} 644
.endfor
CONF_FILES_PERMS+=	/dev/null /var/log/icbd.log \
			${ICBD_OWNER} ${ROOT_GROUP} 644
RCD_SCRIPTS=		icbd

post-extract:
	-${RM} -f ${WRKSRC}/*/.depend

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},' \
		< ${WRKSRC}/etc/icbd.sh > ${WRKDIR}/icbd.sh

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
.for f in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f:Q} ${EGDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/icbd.sh ${PREFIX}/share/examples/rc.d/icbd

.include "../../mk/bsd.pkg.mk"
