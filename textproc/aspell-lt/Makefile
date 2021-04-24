# $NetBSD: Makefile,v 1.3 2021/04/24 00:24:53 wiz Exp $

DISTNAME=	aspell6-lt-1.3
PKGNAME=	${DISTNAME:S/6-/-/1}
CATEGORIES=	textproc
#MASTER_SITES=	ftp://ftp.akl.lt/ispell-lt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	ftp://ftp.akl.lt/ispell-lt/
COMMENT=	Lithuanian language support for aspell
LICENSE=	modified-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
