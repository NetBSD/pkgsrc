# $NetBSD: Makefile,v 1.14 2026/10/25 20:46:22 drixter Exp $

DISTNAME=	pci.ids
PKGNAME=	pciids-20261024
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pciutils/}
GITHUB_PROJECT=	pciids
GITHUB_TAG=	fe7fceb2e1153d495e1deefacf59c5d61c36ef8e

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://pci-ids.ucw.cz/
COMMENT=	Repository of PCI IDs (pci.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

INSTALLATION_DIRS=	share/pciids
NO_BUILD=		yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/pciids-${GITHUB_TAG}/pci.ids ${DESTDIR}${PREFIX}/share/pciids

.include "../../mk/bsd.pkg.mk"
