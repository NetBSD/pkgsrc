# $NetBSD: Makefile,v 1.2 2017/08/16 20:45:45 wiz Exp $
#

DISTNAME=	aspell5-mg-0.03-0
PKGNAME=	${DISTNAME:S/5-/-/1:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/mg/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
#HOMEPAGE=	http://linuxmg.org/
COMMENT=	Malagasy language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
