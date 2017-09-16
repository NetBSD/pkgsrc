# $NetBSD: Makefile,v 1.2 2017/09/16 19:27:14 wiz Exp $
#

DISTNAME=	aspell6-mr-0.10-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/mr/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.janabhaaratii.org.in/
COMMENT=	Marathi language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-hi-[0-9]*

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
