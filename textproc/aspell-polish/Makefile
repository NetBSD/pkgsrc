# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:47 joerg Exp $
#

DISTNAME=	aspell-pl-0.51-0
PKGNAME=	${DISTNAME:C/pl-(.*)-(.*)$/polish-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/pl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Polish language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

UNLIMIT_RESOURCES+=	datasize

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
