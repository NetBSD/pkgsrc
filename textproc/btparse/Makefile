# $NetBSD: Makefile,v 1.8 2004/12/03 15:15:11 wiz Exp $
#

DISTNAME=	btparse-0.33
CATEGORIES=	textproc
MASTER_SITES=	http://starship.python.net/~gward/btOOL/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starship.python.net/~gward/btOOL/
COMMENT=	BibTeX parsing library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PERL5=	build
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
BUILD_TARGET=	lib
TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
