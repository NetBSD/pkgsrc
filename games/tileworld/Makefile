# $NetBSD: Makefile,v 1.11 2004/10/03 00:14:47 tv Exp $

DISTNAME=	tworld-1.1.3
PKGNAME=	${DISTNAME:S/^t/tile/}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.muppetlabs.com/~breadbox/software/tworld/
COMMENT=	"Game based on Chip's Challenge"

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES
GNU_CONFIGURE=	YES

ALL_TARGET=	tworld

MAKE_ENV+=	ECHO="${ECHO}" DATE="${DATE}"

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
