# $NetBSD: Makefile,v 1.9 2004/12/24 03:12:16 wiz Exp $
#

DISTNAME=	aspell-pl-0.51-0
PKGNAME=	${DISTNAME:C/pl-(.*)-(.*)$/polish-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/pl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Polish language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

UNLIMIT_RESOURCES+=	datasize

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
