# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:32 tv Exp $
#

DISTNAME=	aspell-eo-0.50-2
PKGNAME=	${DISTNAME:C/eo-(.*)-(.*)$/esperanto-\1.\2/}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/eo/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Esperanto language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
