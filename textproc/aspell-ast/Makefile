# $NetBSD: Makefile,v 1.2 2017/08/01 17:40:16 wiz Exp $
#

DISTNAME=	aspell6-ast-0.01
PKGNAME=	${DISTNAME:S/6-/-/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ast/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
#HOMEPAGE=	http://softastur.org/Aspell
COMMENT=	Asturian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
