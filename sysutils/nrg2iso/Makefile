# $NetBSD: Makefile,v 1.3 2005/03/19 14:38:47 wiz Exp $
#

DISTNAME=	nrg2iso-0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://gregory.kokanosky.free.fr/v4/linux/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gregory.kokanosky.free.fr/v4/linux/nrg2iso.en.html
COMMENT=	Converts Nero Burning Roms to ISO images

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nrg2iso ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
