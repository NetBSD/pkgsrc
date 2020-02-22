# $NetBSD: Makefile,v 1.13 2020/02/22 19:48:39 sevan Exp $

DISTNAME=	pci.ids
PKGNAME=	pciids-20200222
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pciutils/}
GITHUB_PROJECT= 	pciids
GITHUB_TAG= 	738f0c156f6ae0085b9b695fb3064437d28a3db1

MAINTAINER=	mark@coris.org.uk
HOMEPAGE=	https://pci-ids.ucw.cz/
COMMENT=	Repository of PCI IDs (pci.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

INSTALLATION_DIRS=	share/pciids
NO_BUILD=		yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/pciids-${GITHUB_TAG}/pci.ids ${DESTDIR}${PREFIX}/share/pciids

.include "../../mk/bsd.pkg.mk"
