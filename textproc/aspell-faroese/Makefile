# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:32 tv Exp $
#

DISTNAME=	aspell5-fo-0.2.16-1
PKGNAME=	${DISTNAME:C/5-fo-(.*)-(.*)$/-faroese-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/fo/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Faroese language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
