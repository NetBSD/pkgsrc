# $NetBSD: Makefile,v 1.9 2004/12/24 03:07:34 wiz Exp $
#

DISTNAME=	aspell5-fo-0.2.16-1
PKGNAME=	${DISTNAME:C/5-fo-(.*)-(.*)$/-faroese-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/fo/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Faroese language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
