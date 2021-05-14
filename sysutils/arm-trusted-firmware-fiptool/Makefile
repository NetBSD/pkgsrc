# $NetBSD: Makefile,v 1.6 2021/05/14 11:45:24 nia Exp $

# We override WRKSRC, so we provide our own patches (and thus distinfo)
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/patches

.include "../../sysutils/arm-trusted-firmware/arm-trusted-firmware-dist.mk"

PKGNAME=	${DISTNAME:S/firmware/firmware-fiptool/}
WRKSRC=		${WRKDIR}/${DISTNAME}/tools/fiptool

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiptool ${DESTDIR}${PREFIX}/bin

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
