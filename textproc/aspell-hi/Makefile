# $NetBSD: Makefile,v 1.4 2017/09/16 19:27:11 wiz Exp $
#

DISTNAME=	aspell6-hi-0.02-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/hi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://oriya.sarovar.org/hi-dict.html
COMMENT=	Hindi language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-mr-[0-9]*

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
