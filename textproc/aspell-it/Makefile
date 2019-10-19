# $NetBSD: Makefile,v 1.3 2019/10/19 11:15:49 nia Exp $

DISTNAME=	aspell6-it-2.2_20050523-0
PKGNAME=	${DISTNAME:S/^aspell6/aspell/1:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/it/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Italian language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-italian-[0-9]*
HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
