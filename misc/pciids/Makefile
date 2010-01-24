# $NetBSD: Makefile,v 1.7 2010/01/24 17:11:19 heinz Exp $
#

DISTNAME=	pciids-20090807
CATEGORIES=	misc
MASTER_SITES=	http://people.freebsd.org/~ahze/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mark@coris.org.uk
HOMEPAGE=	http://pciids.sourceforge.net/
COMMENT=	Repository of PCI IDs (pci.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pciids
	${INSTALL_DATA} ${WRKSRC}/pci.ids ${DESTDIR}${PREFIX}/share/pciids

.include "../../mk/bsd.pkg.mk"
