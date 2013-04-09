# $NetBSD: Makefile,v 1.1 2013/04/09 02:33:46 rodent Exp $
#

DISTNAME=	aspell-pl-0.51-0
PKGNAME=	${DISTNAME:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/pl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Polish language support for aspell

HAS_CONFIGURE=	yes

UNLIMIT_RESOURCES+=	datasize

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
