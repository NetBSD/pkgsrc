# $NetBSD: Makefile,v 1.13 2004/12/03 15:15:02 wiz Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		poppassd-${VERSION}
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/

PATCH_SITES=		http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=		qpopper-4.0.5-ipv6-20030313.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://www.eudora.com/qpopper/
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
