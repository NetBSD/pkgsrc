# $NetBSD: Makefile,v 1.10 2004/12/31 14:28:24 minskim Exp $
#

DISTNAME=	aspell-it-0.53-0
PKGNAME=	${DISTNAME:C/it-(.*)-(.*)$/italian-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/it/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Italian language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
