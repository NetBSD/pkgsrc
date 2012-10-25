# $NetBSD: Makefile,v 1.15 2012/10/25 06:55:41 asau Exp $
#

DISTNAME=	aspell-pl-0.51-0
PKGNAME=	${DISTNAME:C/pl-(.*)-(.*)$/polish-\1.\2/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/pl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Polish language support for aspell

HAS_CONFIGURE=	YES

UNLIMIT_RESOURCES+=	datasize

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
