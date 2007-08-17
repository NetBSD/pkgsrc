# $NetBSD: Makefile,v 1.17 2007/08/17 23:10:19 agc Exp $
#

DISTNAME=	ssam-1.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	UTF-8-aware stream editor like sed(1), using the sam command set

GNU_CONFIGURE=	yes
BUILD_TARGET=	tst
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../misc/libutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
