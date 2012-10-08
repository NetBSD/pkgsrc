# $NetBSD: Makefile,v 1.28 2012/10/08 12:19:27 asau Exp $
#

DISTNAME=		qpopper${VERSION}
PKGNAME=		poppassd-${VERSION}
CATEGORIES=		mail
MASTER_SITES=		${QPOPPER_MASTER_SITES}

PATCH_SITES=		${QPOPPER_PATCHSITES}
PATCHFILES=		${QPOPPER_PATCHFILES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		${QPOPPER_HOMEPAGE}
COMMENT=		Qualcomm's password change server mainly for Eudora

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	man/poppassd.8 password/poppassd.c
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"

.include "../../mail/qpopper/Makefile.common"

CONFIGURE_ARGS+=	--enable-poppassd --without-pam
CONFIGURE_ENV+=	CDEFS='-DSMBPASSWD_BINARY=\"${LOCALBASE}/bin/smbpasswd\"'
MAKE_ENV+=	ROOT_USER=${ROOT_USER:Q} ROOT_GROUP=${ROOT_GROUP:Q}

.include "options.mk"

SPECIAL_PERMS+=	libexec/poppassd ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4755

INSTALLATION_DIRS=	${PKGMANDIR}/man8 share/doc libexec
# popper makefile doesn't have an install target...
INSTALL_DIRS=		password
BUILD_DIRS=		common password

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/poppassd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/License.txt				\
		${DESTDIR}${PREFIX}/share/doc/poppassd.License;

.include "../../mk/bsd.pkg.mk"
