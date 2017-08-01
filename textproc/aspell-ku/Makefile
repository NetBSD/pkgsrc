# $NetBSD: Makefile,v 1.2 2017/08/01 14:59:06 wiz Exp $
#

DISTNAME=	aspell5-ku-0.20-1
PKGNAME=	${DISTNAME:S/5-/-/1:S/-1/.1/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ku/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/myspellkurdish/
COMMENT=	Kurdi language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
