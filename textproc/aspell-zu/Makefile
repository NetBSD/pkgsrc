# $NetBSD: Makefile,v 1.2 2015/02/19 14:23:57 mef Exp $
#

DISTNAME=	aspell-zu-0.50-0
#  Following gives aspell-zu.0.50-0
PKGNAME=	${DISTNAME:S/-0/.0/1}
#  Following gives aspell-zu-0.50.0 (etc)
PKGNAME=	${DISTNAME:C/0-([0-9])/0.\1/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/zu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Zulu language support for aspell
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
