# $NetBSD: Makefile,v 1.17 2012/05/21 09:52:11 marino Exp $
#

DISTNAME=	aspell6-es-1.11-2
PKGNAME=	aspell-spanish-1.11.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/es/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Spanish language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
