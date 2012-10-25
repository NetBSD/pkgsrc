# $NetBSD: Makefile,v 1.15 2012/10/25 06:55:39 asau Exp $
#

DISTNAME=	aspell6-ca-20040130-1
PKGNAME=	${DISTNAME:C/6-ca-(.*)-(.*)$/-catalan-\1.\2/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ca/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Catalan language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
