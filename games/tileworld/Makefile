# $NetBSD: Makefile,v 1.27 2015/04/25 14:23:04 tnn Exp $

DISTNAME=	tworld-1.3.0
PKGNAME=	${DISTNAME:S/^t/tile/}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muppetlabs.com/~breadbox/software/tworld/
COMMENT=	"Game based on Chip's Challenge"

USE_TOOLS+=	date gmake
GNU_CONFIGURE=	YES

BUILD_TARGET=	tworld

MAKE_ENV+=	ECHO=${ECHO:Q} DATE=${DATE:Q}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
