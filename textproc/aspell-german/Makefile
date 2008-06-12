# $NetBSD: Makefile,v 1.12 2008/06/12 02:14:47 joerg Exp $
#

DISTNAME=	aspell6-de-20030222-1
PKGNAME=	${DISTNAME:C/6-de-(.*)-(.*)$/-german-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/de/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	German language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
