# $NetBSD: Makefile,v 1.2 2013/04/24 11:15:43 rodent Exp $
#

DISTNAME=	aspell-pl-0.51-0
PKGNAME=	${DISTNAME:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/pl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Polish language support for aspell

CONFLICTS+=	aspell-polish-[0-9]*
HAS_CONFIGURE=	yes

UNLIMIT_RESOURCES+=	datasize

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
