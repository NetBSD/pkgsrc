# $NetBSD: Makefile,v 1.3 2019/10/19 10:58:53 nia Exp $
#

DISTNAME=	aspell6-pt_BR-20131030-12-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-12/.12/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/pt_BR/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Brazilian Portuguese language support for aspell
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
