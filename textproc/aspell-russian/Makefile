# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:45 jlam Exp $
#

DISTNAME=	aspell6-ru-0.99f7-1
PKGNAME=	${DISTNAME:C/6-ru-(.*)-(.*)$/-russian-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ru/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Russian language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
