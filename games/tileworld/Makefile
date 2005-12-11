# $NetBSD: Makefile,v 1.20 2005/12/11 09:40:43 wiz Exp $

DISTNAME=	tworld-1.2.1
PKGNAME=	${DISTNAME:S/^t/tile/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.muppetlabs.com/~breadbox/software/tworld/
COMMENT=	"Game based on Chip's Challenge"

USE_TOOLS+=	date gmake
GNU_CONFIGURE=	YES

BUILD_TARGET=	tworld

MAKE_ENV+=	ECHO=${ECHO:Q} DATE=${DATE:Q}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
