# $NetBSD: Makefile,v 1.11 2003/07/17 21:34:49 grant Exp $
#

DISTNAME=	ssam-1.9
CATEGORIES=	editors
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.westley.demon.co.uk/software.html
COMMENT=	UTF-8-aware stream editor like sed(1), using the sam command set

GNU_CONFIGURE=	yes
ALL_TARGET=	tst
USE_BUILDLINK2=	yes

.include "../../misc/libutf/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
