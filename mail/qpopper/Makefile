# $NetBSD: Makefile,v 1.29 2001/07/26 15:43:28 taca Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		qpopper-${VERSION}
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/

PATCH_SITES=		http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=		qpopper4.0.3-ipv6-20010504.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://www.eudora.com/qpopper/
COMMENT=		Qualcomm's POP server for Eudora

VERSION=		4.0.3

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

.include "Makefile.common"

.if exists(/usr/sbin/user)
USER_CMD=		/usr/sbin/user
GROUP_CMD=		/usr/sbin/group
.else
DEPENDS+=		user>=20000313:../../sysutils/user
USER_CMD=		${LOCALBASE}/sbin/user
GROUP_CMD=		${LOCALBASE}/sbin/group
.endif

pre-build:
	${SED} 's"/usr/local/lib"${LOCALBASE}/libexec"' \
		${WRKSRC}/man/popper.8 > ${WRKSRC}/man/popper.8.$$ && \
	${MV} -f ${WRKSRC}/man/popper.8.$$ ${WRKSRC}/man/popper.8

post-build:
	for FILE in DEINSTALL INSTALL; do \
		${SED}	-e 's|@BINGRP@|${BINGRP}|g' \
			-e 's|@CHGRP@|${CHGRP}|g' \
			-e 's|@CHOWN@|${CHOWN}|g' \
			-e 's|@DB_SUFFIX@|${DB_SUFFIX}|g' \
			-e 's|@USER_CMD@|${USER_CMD}|g' \
			-e 's|@QPOPPER_USER@|${QPOPPER_USER}|g' \
			-e 's|@PKG_PREFIX@|${PREFIX}|g' \
			-e 's|@QPOPPER_APOP_AUTH@|${QPOPPER_APOP_AUTH}|g' \
			-e 's|@INSTALL_DATA@|${INSTALL_DATA}|g' \
			< ${PKGDIR}/$${FILE} > ${WRKDIR}/$${FILE}; \
	done

pre-install:
	PKG_PREFIX=${LOCALBASE} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/License.txt ${LOCALBASE}/share/doc/qpopper.License
	${INSTALL_DATA} ${WRKSRC}/samples/qpopper.config \
		 ${LOCALBASE}/share/examples
	PKG_PREFIX=${LOCALBASE} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
