# $NetBSD: Makefile,v 1.5 2003/06/02 01:19:35 jschauma Exp $
#

DISTNAME=	tworld-1.0
PKGNAME=	${DISTNAME:S/^t/tile/}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/tworld-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.muppetlabs.com/~breadbox/software/tworld/
COMMENT=	"Game based on Chip's Challenge"

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
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
