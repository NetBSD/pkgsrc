# $NetBSD: Makefile,v 1.1.1.1 2003/02/15 08:13:20 salo Exp $
#

DISTNAME=	tworld-1.0
PKGNAME=	${DISTNAME:S/^t/tile/}
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.muppetlabs.com/~breadbox/software/tworld/
COMMENT=	"Game based on Chip's Challenge"

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/tworld-1.0
ALL_TARGET=	tworld

MAKE_ENV+=	ECHO="${ECHO}" DATE="${DATE}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tworld
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tworld/
	${INSTALL_DATA} ${WRKSRC}/docs/tworld.html ${PREFIX}/share/doc/tworld/

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
