# $NetBSD: Makefile,v 1.5 2019/07/06 19:12:47 nia Exp $

DISTNAME=	aspell5-ga-4.8-0
PKGNAME=	${DISTNAME:S/5-/-/1:S/-0/.0/1}
CATEGORIES=	textproc
#MASTER_SITES=	${MASTER_SITE_GITHUB:=kscanne/}
MASTER_SITES=	https://github.com/kscanne/gaelspell/releases/download/v4.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Irish language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-gaeilge-[0-9]*
HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
