# $NetBSD: Makefile,v 1.9 2004/12/24 03:05:04 wiz Exp $
#

DISTNAME=	aspell6-cs-20040614-1
PKGNAME=	${DISTNAME:C/6-cs-(.*)-(.*)$/-czech-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/cs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Czech language support for aspell

BROKEN=		Makes aspell dump core; see aspell bug report 1090342

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
