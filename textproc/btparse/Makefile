# $NetBSD: Makefile,v 1.10 2005/07/16 01:19:23 jlam Exp $
#

DISTNAME=	btparse-0.33
CATEGORIES=	textproc
MASTER_SITES=	http://starship.python.net/~gward/btOOL/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starship.python.net/~gward/btOOL/
COMMENT=	BibTeX parsing library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	perl
GNU_CONFIGURE=	YES
BUILD_TARGET=	lib
TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
