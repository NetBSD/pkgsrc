# $NetBSD: Makefile,v 1.1.1.1 2003/07/17 19:09:23 wennmach Exp $
# FreeBSD Id: ports/devel/avrdude/Makefile,v 1.4 2003/04/19 14:13:25 bsd Exp

DISTNAME=	avrdude-4.1.0
CATEGORIES=	cross
MASTER_SITES=	http://savannah.nongnu.org/download/avrdude/stable.pkg/4.1.0/

MAINTAINER=	karlj@mdstud.chalmers.se
HOMEPAGE=	http://www.bsdhome.com/avrdude/
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs

BUILD_DEPENDS=	teTeX>=1.0:../../print/teTeX

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-versioned-doc

.include "../../mk/bsd.pkg.mk"
