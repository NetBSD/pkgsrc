# $NetBSD: Makefile,v 1.7 2023/10/24 22:11:03 wiz Exp $

# We override WRKSRC, so we provide our own patches (and thus distinfo)
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/patches

PKGREVISION= 1
.include "../../sysutils/arm-trusted-firmware/arm-trusted-firmware-dist.mk"

PKGNAME=	${DISTNAME:S/firmware/firmware-fiptool/}
WRKSRC=		${WRKDIR}/${DISTNAME}/tools/fiptool

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiptool ${DESTDIR}${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
