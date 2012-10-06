# $NetBSD: Makefile,v 1.26 2012/10/06 11:54:56 asau Exp $

DISTNAME=	tworld-1.3.0
PKGNAME=	${DISTNAME:S/^t/tile/}
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
