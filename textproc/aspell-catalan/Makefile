# $NetBSD: Makefile,v 1.9 2004/12/24 03:03:46 wiz Exp $
#

DISTNAME=	aspell6-ca-20040130-1
PKGNAME=	${DISTNAME:C/6-ca-(.*)-(.*)$/-catalan-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ca/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Catalan language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
