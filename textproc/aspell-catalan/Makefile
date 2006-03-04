# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:44 jlam Exp $
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

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
