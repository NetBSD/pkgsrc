# $NetBSD: Makefile,v 1.19 2005/06/15 05:26:20 taca Exp $
#

DISTNAME=		qpopper${VERSION}
PKGREVISION=		1
PKGNAME=		poppassd-${VERSION}
CATEGORIES=		mail
MASTER_SITES=		${QPOPPER_MASTER_SITES}

PATCH_SITES=		${QPOPPER_PATCHSITES}
PATCHFILES=		${QPOPPER_PATCHFILES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		${QPOPPER_HOMEPAGE}
COMMENT=		Qualcomm's password change server mainly for Eudora

.include "../qpopper/Makefile.common"

CONFIGURE_ARGS+=	--enable-poppassd --without-pam
CONFIGURE_ENV+=	CDEFS='-DSMBPASSWD_BINARY=\"${LOCALBASE}/bin/smbpasswd\"'
MAKE_ENV+=	ROOT_USER=${ROOT_USER} ROOT_GROUP=${ROOT_GROUP}

.include "options.mk"

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
