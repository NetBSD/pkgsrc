# $NetBSD: Makefile,v 1.9 2004/01/24 13:30:57 grant Exp $
#

DISTNAME=	tworld-1.0
PKGNAME=	${DISTNAME:S/^t/tile/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.muppetlabs.com/~breadbox/software/tworld/
COMMENT=	"Game based on Chip's Challenge"

WRKSRC=		${WRKDIR}/tworld-1.0
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES
GNU_CONFIGURE=	YES

ALL_TARGET=	tworld

MAKE_ENV+=	ECHO="${ECHO}" DATE="${DATE}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tworld
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tworld/
	${INSTALL_DATA} ${WRKSRC}/docs/tworld.html ${PREFIX}/share/doc/tworld/

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
