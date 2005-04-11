# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:33 tv Exp $
#

DISTNAME=	aspell-uk-0.51-0
PKGNAME=	${DISTNAME:C/uk-(.*)-(.*)$/ukrainian-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/uk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Ukrainian language support for aspell

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
