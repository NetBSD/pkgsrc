# $NetBSD: Makefile,v 1.3 2008/04/26 05:07:09 bjs Exp $
#

DISTNAME=	pciids-20080312
CATEGORIES=	misc
MASTER_SITES=	http://people.freebsd.org/~ahze/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mark@coris.org.uk
HOMEPAGE=	http://pciids.sourceforge.net/
COMMENT=	Repository of PCI IDs (pci.ids database)

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pciids
	${INSTALL_DATA} ${WRKSRC}/pci.ids ${DESTDIR}${PREFIX}/share/pciids
	${INSTALL_DATA} ${WRKSRC}/pci.db ${DESTDIR}${PREFIX}/share/pciids

.include "../../mk/bsd.pkg.mk"
