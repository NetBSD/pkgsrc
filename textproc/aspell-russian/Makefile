# $NetBSD: Makefile,v 1.6 2003/07/17 22:54:08 grant Exp $
#

DISTNAME=	aspell-ru-0.50-2
PKGNAME=	${DISTNAME:C/ru-(.*)-(.*)$/russian-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/ru/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Russian language support for aspell

USE_BUILDLINK2=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
