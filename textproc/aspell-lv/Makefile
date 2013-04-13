# $NetBSD: Makefile,v 1.1 2013/04/13 11:23:28 rodent Exp $
#

DISTNAME=	aspell6-lv-0.5.5-1
PKGNAME=	${DISTNAME:S/6-/-/1:S/-1/.1/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/lv/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.integoplus.lv/opensource/openoffice.html
COMMENT=	Latvian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
