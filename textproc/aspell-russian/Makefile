# $NetBSD: Makefile,v 1.14 2011/04/22 13:44:48 obache Exp $
#

DISTNAME=	aspell6-ru-0.99f7-1
PKGNAME=	${DISTNAME:C/6-ru-(.*)-(.*)$/-russian-\1.\2/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ru/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Russian language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
