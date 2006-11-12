# $NetBSD: Makefile,v 1.1.1.1 2006/11/12 11:46:21 jmmv Exp $
#
DISTNAME=	pciids-20061026
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
