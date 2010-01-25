# $NetBSD: Makefile,v 1.4 2010/01/25 21:01:03 is Exp $
#

DISTNAME=		wbd-1.0ucl4
PKGNAME=		wbd-1.0p4
PKGREVISION=		1
CATEGORIES=		mbone tk
MASTER_SITES=		http://www-mice.cs.ucl.ac.uk/multimedia/software/wbd/1.0ucl4/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-mice.cs.ucl.ac.uk/multimedia/software/wbd/
COMMENT=		Multicast WhiteBoarD

MAKE_FILE=		makefile
WRKSRC=			${WRKDIR}/wbd
BUILD_TARGET=		wbd
NO_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wbd ${DESTDIR}${PREFIX}/bin/wbd

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
