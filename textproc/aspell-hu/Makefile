# $NetBSD: Makefile,v 1.4 2020/03/20 11:58:24 nia Exp $
#

DISTNAME=	aspell6-hu-0.99.4.2-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/hu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://magyarispell.sourceforge.net/
COMMENT=	Hungarian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
