# $NetBSD: Makefile,v 1.1 2013/04/12 10:31:25 rodent Exp $
#

DISTNAME=	aspell-mt-0.50-0
PKGNAME=	${DISTNAME:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/mt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://linux.org.mt/spellcheck/
COMMENT=	Maltese language support for aspell
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
