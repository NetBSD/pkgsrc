# $NetBSD: Makefile,v 1.3 2015/04/12 08:47:30 mef Exp $
#

DISTNAME=	aspell6-ca-2.1.5-1
PKGNAME=	${DISTNAME:S/6-/-/1:S/-1/.1/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ca/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Catalan language support for aspell
LICENSE=	gnu-gpl-v1 AND gnu-gpl-v2

CONFLICTS+=	aspell-catalan-[0-9]*
HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
