# $NetBSD: Makefile,v 1.5 2006/03/04 21:30:42 jlam Exp $
#

DISTNAME=	nrg2iso-0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://gregory.kokanosky.free.fr/v4/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gregory.kokanosky.free.fr/v4/linux/nrg2iso.en.html
COMMENT=	Converts Nero Burning Roms to ISO images

PKG_INSTALLATION_TYPES=	overwrite pkgviews


INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nrg2iso ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
