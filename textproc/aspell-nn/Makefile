# $NetBSD: Makefile,v 1.3 2017/09/16 19:27:14 wiz Exp $
#

DISTNAME=	aspell-nn-0.50.1-1
PKGNAME=	${DISTNAME:S/-1/.1/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/nn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.uio.no/~runekl/dictionary.html
COMMENT=	Norwegian Nynorsk language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
