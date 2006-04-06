# $NetBSD: Makefile,v 1.14 2006/04/06 06:22:48 reed Exp $
#

DISTNAME=	aspell6-cs-20040614-1
PKGNAME=	${DISTNAME:C/6-cs-(.*)-(.*)$/-czech-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/cs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Czech language support for aspell

# earlier versions core-dumped on the input
BUILDLINK_API_DEPENDS.aspell+=	aspell>=0.60.2nb1

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
