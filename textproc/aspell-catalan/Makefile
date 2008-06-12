# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:47 joerg Exp $
#

DISTNAME=	aspell6-ca-20040130-1
PKGNAME=	${DISTNAME:C/6-ca-(.*)-(.*)$/-catalan-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ca/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Catalan language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
