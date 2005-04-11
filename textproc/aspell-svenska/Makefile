# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:32 tv Exp $
#

DISTNAME=	aspell-sv-0.51-0
PKGNAME=	${DISTNAME:C/sv-(.*)-(.*)$/svenska-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/sv/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Swedish language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
