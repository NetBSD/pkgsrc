# $NetBSD: Makefile,v 1.3 2003/01/15 00:27:10 salo Exp $
#

DISTNAME=	aspell-slovak-1.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://ispell.hq.sk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://ispell.hq.sk/homepage/
COMMENT=	Slovak language support for aspell

MAKE_ENV+=	SORT="${SORT}"

.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
