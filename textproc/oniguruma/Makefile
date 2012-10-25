# $NetBSD: Makefile,v 1.5 2012/10/25 06:56:09 asau Exp $
#

DISTNAME=	onig-5.9.2
PKGNAME=	${DISTNAME:S/onig/oniguruma/}
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.jp/kosako3/oniguruma/
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	atest

.include "../../mk/bsd.pkg.mk"
