# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:58 wiz Exp $
#

DISTNAME=	nrg2iso-0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://gregory.kokanosky.free.fr/v4/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gregory.kokanosky.free.fr/v4/linux/nrg2iso.en.html
COMMENT=	Converts Nero Burning Roms to ISO images

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nrg2iso ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
