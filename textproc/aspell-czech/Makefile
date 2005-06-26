# $NetBSD: Makefile,v 1.11 2005/06/26 05:20:07 wiz Exp $
#

DISTNAME=	aspell6-cs-20040614-1
PKGNAME=	${DISTNAME:C/6-cs-(.*)-(.*)$/-czech-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/cs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Czech language support for aspell

# earlier versions core-dumped on the input
BUILDLINK_DEPENDS.aspell+=	aspell>=0.60.2nb1

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
