# $NetBSD: Makefile,v 1.2 2003/01/02 12:21:46 salo Exp $
#

DISTNAME=	aspell-slovak-1.1
CATEGORIES=	textproc
MASTER_SITES=	http://ispell.hq.sk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://ispell.hq.sk/homepage/
COMMENT=	Slovak language support for aspell

DEPENDS+=	aspell>=0.33.7.1:../../textproc/aspell

MAKE_ENV+=	ECHO="${ECHO}" SORT="${SORT}"

.include "../../mk/bsd.pkg.mk"
