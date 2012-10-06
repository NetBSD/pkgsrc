# $NetBSD: Makefile,v 1.1 2012/10/06 16:43:37 taca Exp $
#

DISTNAME=	transifex-transifex-client-0.8.0-gb001295
PKGNAME=	${DISTNAME:S/transifex-//:C/-[a-z0-9]+$//}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/transifex/transifex-client/tarball/0.8

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.soycms.net/web/files/soycms/
COMMENT=	Transifex Command-line Client
LICENSE=	gnu-gpl-v2

FETCH_USING=    curl
WRKSRC=		${WRKDIR}/${DISTNAME:S/0.8.0-g//}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
