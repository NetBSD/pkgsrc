# $NetBSD: Makefile,v 1.3 2003/08/07 14:00:35 seb Exp $
# FreeBSD Id: ports/devel/avrdude/Makefile,v 1.4 2003/04/19 14:13:25 bsd Exp

DISTNAME=	avrdude-4.1.0
CATEGORIES=	cross
MASTER_SITES=	http://savannah.nongnu.org/download/avrdude/stable.pkg/4.1.0/

MAINTAINER=	karlj@mdstud.chalmers.se
HOMEPAGE=	http://www.bsdhome.com/avrdude/
COMMENT=	Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers

BUILD_DEPENDS=	teTeX>=1.0:../../print/teTeX

GNU_CONFIGURE=	yes
USE_NEW_TEXINFO=	YES
INFO_FILES=	avrdude.info

CONFIGURE_ARGS=	--disable-versioned-doc

.include "../../mk/bsd.pkg.mk"
