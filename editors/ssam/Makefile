# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:39 tv Exp $
#

DISTNAME=	ssam-1.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.westley.demon.co.uk/software.html
COMMENT=	UTF-8-aware stream editor like sed(1), using the sam command set

GNU_CONFIGURE=	yes
ALL_TARGET=	tst
USE_BUILDLINK3=	yes

.include "../../misc/libutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
