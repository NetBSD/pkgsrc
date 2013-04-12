# $NetBSD: Makefile,v 1.1 2013/04/12 12:25:05 rodent Exp $
#

DISTNAME=	aspell-sl-0.50-0
PKGNAME=	${DISTNAME:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/sl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Slovenian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
