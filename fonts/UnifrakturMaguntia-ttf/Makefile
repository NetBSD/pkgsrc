# $NetBSD: Makefile,v 1.4 2020/11/06 18:04:24 maya Exp $

DISTNAME=	UnifrakturMaguntia.2017-03-19
PKGNAME=	${DISTNAME:S/-//g:S/./-ttf-0./}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unifraktur/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unifraktur.sourceforge.net/maguntia.html
COMMENT=	Unicode Fraktur Font
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
