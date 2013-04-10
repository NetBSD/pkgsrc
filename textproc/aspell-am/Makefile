# $NetBSD: Makefile,v 1.1 2013/04/10 12:03:55 rodent Exp $
#

DISTNAME=	aspell6-am-0.03-1
PKGNAME=	${DISTNAME:S/6-/-/1:S/-1/.1/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/am/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	ftp://ftp.gnu.org/gnu/aspell/dict/am/
COMMENT=	Amharic language support for aspell
LICENSE=	public-domain

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
