# $NetBSD: Makefile,v 1.1 2013/04/11 11:58:03 rodent Exp $
#

DISTNAME=	aspell5-id-1.2-0
PKGNAME=	${DISTNAME:S/5-/-/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/id/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://rahmatm.samik-ibrahim.vlsm.org/
COMMENT=	Indonesian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
