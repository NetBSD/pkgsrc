# $NetBSD: Makefile,v 1.7 2003/07/17 22:54:08 grant Exp $
#

DISTNAME=	aspell-sk-0.50.3-1.1
PKGNAME=	${DISTNAME:C/sk-(.*)-(.*)$/slovak-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://ispell.hq.sk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://ispell.hq.sk/homepage/
COMMENT=	Slovak language support for aspell

USE_BUILDLINK2=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

MAKE_ENV+=	SORT="${SORT}"

.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
