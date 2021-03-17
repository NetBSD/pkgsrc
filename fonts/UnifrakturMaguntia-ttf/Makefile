# $NetBSD: Makefile,v 1.5 2021/03/17 21:32:25 wiz Exp $

DISTNAME=	UnifrakturMaguntia.2017-03-19
PKGNAME=	${DISTNAME:S/-//g:S/./-ttf-0./}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unifraktur/}
EXTRACT_SUFX=	.zip

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://unifraktur.sourceforge.net/maguntia.html
COMMENT=	Unicode Fraktur Font
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
