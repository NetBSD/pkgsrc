# $NetBSD: Makefile,v 1.1 2013/04/12 00:01:28 rodent Exp $
#

DISTNAME=	aspell6-mn-0.06-2
PKGNAME=	${DISTNAME:S/6-/-/1:S/-2/.2/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/mn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.openmn.org/
COMMENT=	Mongolian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
