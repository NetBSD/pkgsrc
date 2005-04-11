# $NetBSD: Makefile,v 1.13 2005/04/11 21:47:32 tv Exp $
#

DISTNAME=	aspell-sk-0.52-0
PKGNAME=	${DISTNAME:C/sk-(.*)-(.*)/slovak-\1.\2/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://spell.linux.sk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://spell.linux.sk/
COMMENT=	Slovak language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
