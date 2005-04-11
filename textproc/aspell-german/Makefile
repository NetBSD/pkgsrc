# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:32 tv Exp $
#

DISTNAME=	aspell6-de-20030222-1
PKGNAME=	${DISTNAME:C/6-de-(.*)-(.*)$/-german-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/de/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	German language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
