# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:44 jlam Exp $
#

DISTNAME=	aspell-eo-0.50-2
PKGNAME=	${DISTNAME:C/eo-(.*)-(.*)$/esperanto-\1.\2/}
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/eo/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Esperanto language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
