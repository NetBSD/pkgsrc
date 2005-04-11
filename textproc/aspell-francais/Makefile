# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:32 tv Exp $
#

DISTNAME=	aspell-fr-0.50-3
PKGNAME=	${DISTNAME:C/fr-(.*)-(.*)$/francais-\1.\2/}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/fr/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	French language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
