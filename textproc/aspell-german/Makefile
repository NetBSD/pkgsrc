# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:18 tv Exp $
#

DISTNAME=	aspell-de-0.50-2
PKGNAME=	${DISTNAME:C/de-(.*)-(.*)$/german-\1.\2/}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/de/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	German language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

post-install:
	(cd ${PREFIX}/lib/aspell && ${LN} -s german.alias ngerman.alias)

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
