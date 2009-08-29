# $NetBSD: Makefile,v 1.25 2009/08/29 11:42:04 wiz Exp $

DISTNAME=	tworld-1.3.0
PKGNAME=	${DISTNAME:S/^t/tile/}
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muppetlabs.com/~breadbox/software/tworld/
COMMENT=	"Game based on Chip's Challenge"

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	date gmake
GNU_CONFIGURE=	YES

BUILD_TARGET=	tworld

MAKE_ENV+=	ECHO=${ECHO:Q} DATE=${DATE:Q}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
