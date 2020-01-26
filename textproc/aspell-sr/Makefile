# $NetBSD: Makefile,v 1.3 2020/01/26 17:32:13 rillig Exp $
#

DISTNAME=	aspell6-sr-0.02
PKGNAME=	${DISTNAME:S/6-/-/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/sr/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://srpski.org/aspell/
COMMENT=	Serbian language support for aspell
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
