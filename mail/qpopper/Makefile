# $NetBSD: Makefile,v 1.28 2001/06/10 15:08:40 taca Exp $
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

.include "Makefile.common"

.if exists(/usr/sbin/user)
USER_CMD=	/usr/sbin/user
GROUP_CMD=	/usr/sbin/group
.else
DEPENDS+=	user>=20000313:../../sysutils/user
USER_CMD=	${LOCALBASE}/sbin/user
GROUP_CMD=	${LOCALBASE}/sbin/group
.endif

pre-build:
	${SED} 's"/usr/local/lib"${LOCALBASE}/libexec"' \
		${WRKSRC}/man/popper.8 > ${WRKSRC}/man/popper.8.$$ && \
	${MV} -f ${WRKSRC}/man/popper.8.$$ ${WRKSRC}/man/popper.8

pre-install:
	@${USER_CMD} info -e ${QPOPPER_USER} || \
		${USER_CMD} add -g ${BINGRP} \
			-d /nonexistent -s /sbin/nologin ${QPOPPER_USER}

post-install:
	@if [ -f ${DESTDIR}/etc/apop.auth.db ]; then \
		${CHOWN} ${QPOPPER_USER} ${DESTDIR}/etc/apop.auth.db; \
		${CHGRP} ${BINGRP} ${DESTDIR}/etc/apop.auth.db; \
	fi
	${INSTALL_DATA} ${WRKSRC}/License.txt ${LOCALBASE}/share/doc/qpopper.License
	${INSTALL_DATA} ${WRKSRC}/samples/qpopper.config \
		 ${LOCALBASE}/share/examples
	@${SETENV} PKG_PREFIX=${LOCALBASE} ${SH} ${INSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
