# $NetBSD: Makefile,v 1.1 2022/02/09 01:57:57 mrg Exp $

# We override WRKSRC, so we provide our own patches (and thus distinfo)
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/patches

.include "../../sysutils/trusted-firmware-a/trusted-firmware-a-dist.mk"

PKGNAME=	${DISTNAME:S/arm-trusted-firmware/trusted-firmware-a-fiptool/}
WRKSRC=		${WRKDIR}/${DISTNAME}/tools/fiptool

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiptool ${DESTDIR}${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
