# $NetBSD: Makefile,v 1.9 2004/12/24 03:06:43 wiz Exp $
#

DISTNAME=	aspell6-en-6.0-0
PKGNAME=	aspell-english-6.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/en/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	English language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
