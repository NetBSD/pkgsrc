# $NetBSD: Makefile,v 1.3 2003/04/20 19:26:19 cjep Exp $
#

DISTNAME=	aspell-pt-0.50-2
PKGNAME=	${DISTNAME:C/pt-(.*)-(.*)$/portuguese-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/pt/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Portuguese language support for aspell

USE_BUILDLINK2=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
