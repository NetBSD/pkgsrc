# $NetBSD: Makefile,v 1.4 2003/07/29 15:55:14 jmmv Exp $
#

DISTNAME=	i2cbd-2.0_BETA0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.draga.com/~jwise/i2cb/
COMMENT=	Next generation Internet Citizens Band chat server

.include "../../mk/bsd.prefs.mk"

ICBD_OWNER?=	root
PLIST_SUBST+=	ICBD_OWNER=${ICBD_OWNER} \
		CHOWN=${CHOWN} \
		TOUCH=${TOUCH}

post-extract:
		-${RM} -f ${WRKSRC}/*/.depend

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/etc/icbd
		${CHOWN} ${ICBD_OWNER} ${PREFIX}/etc/icbd
		${CHMOD} 755 ${PREFIX}/etc/icbd
		for f in motd icbd_help icbd.deny news.1 ; do \
			${INSTALL_DATA} ${WRKSRC}/etc/$$f ${PREFIX}/etc/icbd ; \
		done
		${CHOWN} -R ${ICBD_OWNER} ${PREFIX}/etc/icbd
		${TOUCH} /var/log/icbd.log
		${CHOWN} ${ICBD_OWNER} /var/log/icbd.log
		${SED} \
			-e 's,@PREFIX@,${PREFIX},' \
			<${WRKSRC}/etc/icbd.sh  >${WRKDIR}/icbd.sh
		${INSTALL_SCRIPT} ${WRKDIR}/icbd.sh ${PREFIX}/etc/rc.d/icbd

.include "../../mk/bsd.pkg.mk"
