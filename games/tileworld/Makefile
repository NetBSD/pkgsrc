# $NetBSD: Makefile,v 1.16 2005/05/16 04:45:40 jlam Exp $

DISTNAME=	tworld-1.2.1
PKGNAME=	${DISTNAME:S/^t/tile/}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.muppetlabs.com/~breadbox/software/tworld/
COMMENT=	"Game based on Chip's Challenge"

USE_GNU_TOOLS+=	make
USE_TOOLS+=	date
USE_X11=	YES
GNU_CONFIGURE=	YES

BUILD_TARGET=	tworld

MAKE_ENV+=	ECHO="${ECHO}" DATE="${DATE}"

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
