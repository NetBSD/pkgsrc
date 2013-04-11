# $NetBSD: Makefile,v 1.1 2013/04/11 11:04:41 rodent Exp $
#

DISTNAME=	aspell6-he-1.0-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/he/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.ivrix.org.il/projects/spell-checker/
COMMENT=	Hebrew language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
