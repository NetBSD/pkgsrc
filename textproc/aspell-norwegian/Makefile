# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:00 joerg Exp $
#

DISTNAME=	aspell-nb-0.50.1-0
PKGNAME=	${DISTNAME:C/nb-(.*)-(.*)$/norwegian-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/nb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Norwegian language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
