# $NetBSD: Makefile,v 1.4 2010/09/10 08:26:38 taca Exp $
#

DISTNAME=	onig-5.9.2
PKGNAME=	${DISTNAME:S/onig/oniguruma/}
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.jp/kosako3/oniguruma/
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	atest

.include "../../mk/bsd.pkg.mk"
