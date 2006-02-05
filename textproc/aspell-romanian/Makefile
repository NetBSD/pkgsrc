# $NetBSD: Makefile,v 1.12 2006/02/05 23:11:00 joerg Exp $
#

DISTNAME=	aspell-ro-0.50-2
PKGNAME=	${DISTNAME:C/ro-(.*)-(.*)$/romanian-\1.\2/}
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ro/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Romanian language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
