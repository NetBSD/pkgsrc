# $NetBSD: Makefile,v 1.16 2012/10/25 06:55:41 asau Exp $
#

DISTNAME=	aspell-it-0.53-0
PKGNAME=	${DISTNAME:C/it-(.*)-(.*)$/italian-\1.\2/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/it/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Italian language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
