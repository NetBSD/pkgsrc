# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:32 tv Exp $
#

DISTNAME=	aspell-nb-0.50.1-0
PKGNAME=	${DISTNAME:C/nb-(.*)-(.*)$/norwegian-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/nb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Norwegian language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
