# $NetBSD: Makefile,v 1.6 2008/06/12 20:44:52 heinz Exp $
#

DISTNAME=	nrg2iso-0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://gregory.kokanosky.free.fr/v4/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gregory.kokanosky.free.fr/v4/linux/nrg2iso.en.html
COMMENT=	Converts Nero Burning Roms to ISO images

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews


INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nrg2iso ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
