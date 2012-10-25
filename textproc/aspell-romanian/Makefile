# $NetBSD: Makefile,v 1.18 2012/10/25 06:55:41 asau Exp $
#

DISTNAME=	aspell5-ro-3.3-2
PKGNAME=	aspell-romanian-3.3.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ro/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Romanian language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
