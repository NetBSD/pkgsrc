# $NetBSD: Makefile,v 1.3 2010/05/07 08:34:23 ahoka Exp $
#

DISTNAME=	onig-5.9.1
PKGNAME=	${DISTNAME:S/onig/oniguruma/}
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.jp/kosako3/oniguruma/
COMMENT=	Regular expressions library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	atest

.include "../../mk/bsd.pkg.mk"
