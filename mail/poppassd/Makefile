# $NetBSD: Makefile,v 1.2 2001/07/26 15:44:44 taca Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		poppassd-${VERSION}
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/

PATCH_SITES=		http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=		qpopper4.0.3-ipv6-20010504.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://www.eudora.com/qpopper/
COMMENT=		Qualcomm's password change server mainly for Eudora

VERSION=		4.0.3
CONFIGURE_ARGS+=	--enable-poppassd
CONFIGURE_ENV+=	CDEFS='-DSMBPASSWD_BINARY=\"${LOCALBASE}/bin/smbpasswd\"'

.include "../qpopper/Makefile.common"

do-build:
	cd ${WRKSRC}/common; ${MAKE} ${ALL_TARGET}
	cd ${WRKSRC}/password; ${MAKE} ${ALL_TARGET}

# popper makefile doesn't have an install target...
do-install:
	cd ${WRKSRC}/password; ${MAKE} ${INSTALL_TARGET}
	${INSTALL_MAN} ${WRKSRC}/man/poppassd.8 ${LOCALBASE}/man/man8
	${INSTALL_DATA} ${WRKSRC}/License.txt \
		${LOCALBASE}/share/doc/poppassd.License;
	PKG_PREFIX=${LOCALBASE} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
