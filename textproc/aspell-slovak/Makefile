# $NetBSD: Makefile,v 1.8 2004/02/11 04:35:21 xtraeme Exp $
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

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

MAKE_ENV+=	SORT="${SORT}"

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
