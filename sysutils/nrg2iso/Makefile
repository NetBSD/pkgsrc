# $NetBSD: Makefile,v 1.1.1.1 2004/07/14 01:12:54 xtraeme Exp $
#

DISTNAME=	nrg2iso-0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://gregory.kokanosky.free.fr/v4/linux/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gregory.kokanosky.free.fr/v4/linux/nrg2iso.en.html
COMMENT=	Converts Nero Burning Roms to ISO images

USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nrg2iso ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
