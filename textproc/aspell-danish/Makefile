# $NetBSD: Makefile,v 1.2 2003/01/19 06:35:45 salo Exp $
#

DISTNAME=	aspell-da-0.50-2
PKGNAME=	${DISTNAME:C/da-(.*)-(.*)$/danish-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Danish language support for aspell

USE_BUILDLINK2=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
