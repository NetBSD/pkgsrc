# $NetBSD: Makefile,v 1.7 2004/02/11 04:35:21 xtraeme Exp $
#

DISTNAME=	aspell-uk-0.50-3
PKGNAME=	${DISTNAME:C/uk-(.*)-(.*)$/ukrainian-\1.\2/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/uk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Ukrainian language support for aspell

USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
