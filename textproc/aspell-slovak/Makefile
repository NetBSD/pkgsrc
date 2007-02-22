# $NetBSD: Makefile,v 1.15 2007/02/22 19:01:25 wiz Exp $
#

DISTNAME=	aspell-sk-0.52-0
PKGNAME=	${DISTNAME:C/sk-(.*)-(.*)/slovak-\1.\2/}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://sk-spell.sk.cx/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://sk-spell.sk.cx/
COMMENT=	Slovak language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
