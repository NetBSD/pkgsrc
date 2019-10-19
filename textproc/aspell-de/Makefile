# $NetBSD: Makefile,v 1.3 2019/10/19 10:50:22 nia Exp $

DISTNAME=	aspell6-de-20161207-7-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-7/.7/1:S/-0/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/de/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	German language support for aspell

CONFLICTS+=	aspell-german-[0-9]*
HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
