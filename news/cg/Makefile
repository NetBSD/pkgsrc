# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:42 joerg Exp $
#

DISTNAME=	cg-0.4
CATEGORIES=	news
MASTER_SITES=	http://ftp.giga.or.at/pub/nih/cg/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://ftp.giga.or.at/pub/nih/cg/
COMMENT=	Semi-automatic newsgroup binary downloader

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		lex
USE_FEATURES=		regcomp
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
