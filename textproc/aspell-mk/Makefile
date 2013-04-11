# $NetBSD: Makefile,v 1.1 2013/04/11 23:49:37 rodent Exp $
#

DISTNAME=	aspell-mk-0.50-0
PKGNAME=	${DISTNAME:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/mk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Macedonian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
