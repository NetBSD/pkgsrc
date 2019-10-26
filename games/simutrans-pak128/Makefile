# $NetBSD: Makefile,v 1.1 2019/10/26 11:27:10 nia Exp $

DISTNAME=	pak128
PKGNAME=	simutrans-pak128-2.8.1
CATEGORIES=	games
MASTER_SITES=	https://downloads.sourceforge.net/project/simutrans/pak128/pak128%20for%20ST%20120.4.1%20%282.8.1%2C%20priority%20signals%20%2B%20bugfix%29/
DIST_SUBDIR=	simutrans-pak128-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.simutrans.com/
COMMENT=	High resolution graphics set for Simutrans
LICENSE=	artistic

WRKSRC=		${WRKDIR}/simutrans

USE_TOOLS+=	pax
USE_LANGUAGES=	# none
NO_BUILD=	yes

# Save some time...
CHECK_WRKREF_SKIP+=	share/simutrans/pak128/*

INSTALLATION_DIRS+=	share/simutrans/pak128

do-install:
	cd ${WRKSRC}/pak128 && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/simutrans/pak128

.include "../../mk/bsd.pkg.mk"
