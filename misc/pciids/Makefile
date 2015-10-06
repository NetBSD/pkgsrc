# $NetBSD: Makefile,v 1.10.2.1 2015/10/06 18:48:22 spz Exp $

DISTNAME=	pci.ids
PKGNAME=	pciids-20150907
CATEGORIES=	misc
MASTER_SITES=	# dynamically generated file http://pci-ids.ucw.cz/v2.2/
EXTRACT_SUFX=	.bz2

MAINTAINER=	mark@coris.org.uk
HOMEPAGE=	http://pciids.sourceforge.net/
COMMENT=	Repository of PCI IDs (pci.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/pciids
NO_BUILD=		yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/pci.ids ${DESTDIR}${PREFIX}/share/pciids

.include "../../mk/bsd.pkg.mk"
