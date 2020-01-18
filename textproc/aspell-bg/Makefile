# $NetBSD: Makefile,v 1.3 2020/01/18 23:35:23 rillig Exp $
#

DISTNAME=	aspell6-bg-4.1-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/bg/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bgoffice.sourceforge.net/
COMMENT=	Bulgarian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
