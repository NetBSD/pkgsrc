# $NetBSD: Makefile,v 1.5 1998/06/22 12:27:09 agc Exp $
#

DISTNAME=	ssam-1.9
CATEGORIES=	editors
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@netbsd.org

BUILD_DEPENDS=	${PREFIX}/lib/libutf.a:../../misc/libutf
RUN_DEPENDS=	${PREFIX}/etc/langcoll.utf:../../misc/libutf

GNU_CONFIGURE=	yes
ALL_TARGET=	tst

.include "../../mk/bsd.pkg.mk"
