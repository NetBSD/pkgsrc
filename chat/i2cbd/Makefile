# $NetBSD: Makefile,v 1.1.1.1 2002/11/14 00:59:31 hubertf Exp $
#

DISTNAME=	i2cbd-2.0_BETA0
CATEGORIES=	chat
MASTER_SITES=	http://www.draga.com/~jwise/i2cb/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.draga.com/~jwise/i2cb/
COMMENT=	Next generation Internet Citicen's Band chat server

.include "../../mk/bsd.prefs.mk"

ICBD_OWNER?=	root
PLIST_SUBST+=	ICBD_OWNER=${ICBD_OWNER} \
		CHOWN=${CHOWN} \
		TOUCH=${TOUCH}

post-extract:
		-${RM} ${WRKSRC}/*/.depend

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
