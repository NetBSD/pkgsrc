# $NetBSD: Makefile,v 1.1.1.1 2003/01/17 06:45:16 salo Exp $
#

DISTNAME=	aspell-br-0.50-2
PKGNAME=	${DISTNAME:C/br-(.*)-(.*)$/breton-\1.\2/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Breton language support for aspell

USE_BUILDLINK2=	YES
HAS_CONFIGURE=	YES

CONFIGURE_ENV+=	ASPELL=${PREFIX}/bin/aspell
CONFIGURE_ENV+=	WORD_LIST_COMPRESS=${PREFIX}/bin/word-list-compress

MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"

.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
