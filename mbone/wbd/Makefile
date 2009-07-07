# $NetBSD: Makefile,v 1.1.1.1 2009/07/07 16:10:18 sborrill Exp $
#

DISTNAME=		wbd-1.0ucl4
PKGNAME=		wbd-1.0p4
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wbd ${DESTDIR}${PREFIX}/bin/wbd

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
