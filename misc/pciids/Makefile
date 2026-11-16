# $NetBSD: Makefile,v 1.15 2026/11/16 19:08:43 drixter Exp $

DISTNAME=	pci.ids
PKGNAME=	pciids-20261116
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pciutils/}
GITHUB_PROJECT=	pciids
GITHUB_TAG=	7c7e37a74321f1d4573a60377970d327ca034a15

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://pci-ids.ucw.cz/
COMMENT=	Repository of PCI IDs (pci.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

INSTALLATION_DIRS=	share/pciids
NO_BUILD=		yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/pciids-${GITHUB_TAG}/pci.ids ${DESTDIR}${PREFIX}/share/pciids

.include "../../mk/bsd.pkg.mk"
