# $NetBSD: Makefile,v 1.13.4.1 2005/06/05 18:40:05 salo Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		poppassd-${VERSION}
CATEGORIES=		mail
MASTER_SITES=		${QPOPPER_MASTER_SITES}

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		${QPOPPER_HOMEPAGE}
COMMENT=		Qualcomm's password change server mainly for Eudora

.include "../qpopper/Makefile.common"

USE_BUILDLINK3=		yes
CONFIGURE_ARGS+=	--enable-poppassd
CONFIGURE_ENV+=	CDEFS='-DSMBPASSWD_BINARY=\"${LOCALBASE}/bin/smbpasswd\"'
MAKE_ENV+=	ROOT_USER=${ROOT_USER} ROOT_GROUP=${ROOT_GROUP}

do-build:
.for DIR in common password
	cd ${WRKSRC}/${DIR}; ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_TARGET}
.endfor

# popper makefile doesn't have an install target...
do-install:
	cd ${WRKSRC}/password; ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}
	${INSTALL_MAN} ${WRKSRC}/man/poppassd.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/License.txt				\
		${PREFIX}/share/doc/poppassd.License;

.include "../../mk/bsd.pkg.mk"
