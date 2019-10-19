# $NetBSD: Makefile,v 1.3 2019/10/19 11:08:31 nia Exp $

DISTNAME=	aspell6-sk-2.01-2
PKGNAME=	${DISTNAME:S/aspell6/aspell/1:S/-2$/.2/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/sk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Slovak language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-slovak-[0-9]*
HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
