# $NetBSD: Makefile,v 1.12 2004/12/31 14:28:24 minskim Exp $
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

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
