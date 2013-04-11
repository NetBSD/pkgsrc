# $NetBSD: Makefile,v 1.1 2013/04/11 11:39:25 rodent Exp $
#

DISTNAME=	aspell6-hus-0.03-1
PKGNAME=	${DISTNAME:S/6-/-/1:S/-1/.1/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/hus/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Huastec language support for aspell
LICENSE=	gnu-gpl-v3

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
