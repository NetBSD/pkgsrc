# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:47 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
