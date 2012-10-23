# $NetBSD: Makefile,v 1.7 2012/10/23 19:51:15 asau Exp $
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
	${INSTALL_PROGRAM} ${WRKSRC}/nrg2iso ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
