# $NetBSD: Makefile,v 1.3 2019/10/19 11:12:13 nia Exp $

DISTNAME=	aspell6-eo-2.1.20000225a-2
PKGNAME=	${DISTNAME:S/aspell6/aspell/1:S/-2$/.2/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/eo/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Esperanto language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-esperanto-[0-9]*
HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
