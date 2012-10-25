# $NetBSD: Makefile,v 1.16 2012/10/25 06:55:41 asau Exp $
#

DISTNAME=	aspell-el-0.50-3
PKGNAME=	${DISTNAME:C/el-(.*)-(.*)$/greek-\1.\2/}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/el/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Greek language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
