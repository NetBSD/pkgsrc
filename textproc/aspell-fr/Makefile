# $NetBSD: Makefile,v 1.2 2013/04/24 11:15:43 rodent Exp $
#

DISTNAME=	aspell-fr-0.50-3
PKGNAME=	${DISTNAME:S/-3/.3/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/fr/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	French language support for aspell

CONFLICTS+=	aspell-francais-[0-9]*
HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
