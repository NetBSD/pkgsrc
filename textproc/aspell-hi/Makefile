# $NetBSD: Makefile,v 1.3 2017/08/01 16:47:45 wiz Exp $
#

DISTNAME=	aspell6-hi-0.02-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/hi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
#HOMEPAGE=	http://oriya.sarovar.org/hi-dict.html
COMMENT=	Hindi language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-mr-[0-9]*

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
