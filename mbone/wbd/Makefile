# $NetBSD: Makefile,v 1.8 2013/06/04 22:16:39 tron Exp $
#

DISTNAME=		wbd-1.0ucl4
PKGNAME=		wbd-1.0p4
PKGREVISION=		4
CATEGORIES=		mbone tk
MASTER_SITES=		http://www-mice.cs.ucl.ac.uk/multimedia/software/wbd/1.0ucl4/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-mice.cs.ucl.ac.uk/multimedia/software/wbd/
COMMENT=		Multicast WhiteBoarD

MAKE_FILE=		makefile
WRKSRC=			${WRKDIR}/wbd
BUILD_TARGET=		wbd
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wbd ${DESTDIR}${PREFIX}/bin/wbd

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
