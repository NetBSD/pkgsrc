# $NetBSD: Makefile,v 1.6 2004/10/18 04:15:14 rumble Exp $
# FreeBSD Id: ports/devel/avrdude/Makefile,v 1.4 2003/04/19 14:13:25 bsd Exp

DISTNAME=	avrdude-4.1.0
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	http://savannah.nongnu.org/download/avrdude/stable.pkg/4.1.0/

MAINTAINER=	karlj@mdstud.chalmers.se
HOMEPAGE=	http://www.bsdhome.com/avrdude/
COMMENT=	Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers

USE_BUILDLINK3=		YES
USE_GNU_READLINE=	YES

BUILD_DEPENDS=	teTeX>=1.0:../../print/teTeX

GNU_CONFIGURE=	yes
INFO_FILES=	avrdude.info

CONFIGURE_ARGS=	--disable-versioned-doc

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
