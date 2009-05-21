# $NetBSD: Makefile,v 1.18 2009/05/21 00:21:57 zafer Exp $
#

DISTNAME=	ssam-1.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	UTF-8-aware stream editor like sed(1), using the sam command set

GNU_CONFIGURE=	yes
BUILD_TARGET=	tst
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../misc/libutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
