# $NetBSD: Makefile,v 1.14 2011/04/22 13:44:48 obache Exp $
#

DISTNAME=	aspell-sv-0.51-0
PKGNAME=	${DISTNAME:C/sv-(.*)-(.*)$/svenska-\1.\2/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/sv/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Swedish language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
