# $NetBSD: Makefile,v 1.4 2003/01/17 01:23:57 salo Exp $
#

DISTNAME=	aspell-slovak-1.1
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://ispell.hq.sk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://ispell.hq.sk/homepage/
COMMENT=	Slovak language support for aspell

USE_BUILDLINK2=	YES

MAKE_ENV+=	SORT="${SORT}"

.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
