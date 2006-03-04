# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:44 jlam Exp $
#

DISTNAME=	aspell-it-0.53-0
PKGNAME=	${DISTNAME:C/it-(.*)-(.*)$/italian-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/it/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Italian language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
