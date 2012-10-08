# $NetBSD: Makefile,v 1.9 2012/10/08 09:57:34 asau Exp $
#

DISTNAME=	pciids-20091229
CATEGORIES=	misc
MASTER_SITES=	http://people.freebsd.org/~ahze/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mark@coris.org.uk
HOMEPAGE=	http://pciids.sourceforge.net/
COMMENT=	Repository of PCI IDs (pci.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pciids
	${INSTALL_DATA} ${WRKSRC}/pci.ids ${DESTDIR}${PREFIX}/share/pciids

.include "../../mk/bsd.pkg.mk"
