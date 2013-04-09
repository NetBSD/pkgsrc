# $NetBSD: Makefile,v 1.1 2013/04/09 02:33:37 rodent Exp $
#

DISTNAME=	aspell6-cs-20040614-1
PKGNAME=	${DISTNAME:S/6-/-/1:S/-1/.1/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/cs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Czech language support for aspell

# earlier versions core-dumped on the input
BUILDLINK_API_DEPENDS.aspell+=	aspell>=0.60.2nb1

HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
