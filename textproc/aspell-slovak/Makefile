# $NetBSD: Makefile,v 1.9 2004/04/21 08:42:34 salo Exp $
#

DISTNAME=	aspell-sk-0.52-0
PKGNAME=	${DISTNAME:C/sk-(.*)-(.*)/slovak-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	http://spell.linux.sk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://spell.linux.sk/
COMMENT=	Slovak language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
