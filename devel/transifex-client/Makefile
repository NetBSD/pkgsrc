# $NetBSD: Makefile,v 1.2 2013/05/23 13:17:52 taca Exp $
#

DISTNAME=	transifex-transifex-client-0.8.0-gb001295
PKGNAME=	${DISTNAME:S/transifex-//:C/-[a-z0-9]+$//}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/transifex/transifex-client/tarball/0.8

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/transifex/transifex-client
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

FETCH_USING=    curl
WRKSRC=		${WRKDIR}/${DISTNAME:S/0.8.0-g//}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
