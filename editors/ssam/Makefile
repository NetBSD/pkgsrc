# $NetBSD: Makefile,v 1.4 1998/04/24 09:20:34 agc Exp $
#

DISTNAME=	ssam-1.9
CATEGORIES=	editors
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@netbsd.org

BUILD_DEPENDS=	${PREFIX}/lib/libutf.a:../../misc/libutf
RUN_DEPENDS=	${PREFIX}/etc/langcoll.utf:../../misc/libutf

MAN1=		ssam.1
GNU_CONFIGURE=	yes
ALL_TARGET=	tst

.include "../../mk/bsd.pkg.mk"
