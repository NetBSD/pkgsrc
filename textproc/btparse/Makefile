# $NetBSD: Makefile,v 1.7 2004/04/12 01:58:24 minskim Exp $
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
ALL_TARGET=	lib
TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
