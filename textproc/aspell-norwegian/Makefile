# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:18 tv Exp $
#

DISTNAME=	aspell-no-0.50-2
PKGNAME=	${DISTNAME:C/no-(.*)-(.*)$/norwegian-\1.\2/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/no/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Norwegian language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
