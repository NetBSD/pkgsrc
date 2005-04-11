# $NetBSD: Makefile,v 1.8 2005/04/11 21:45:10 tv Exp $

DISTNAME=	avrdude-4.1.0
PKGREVISION=	2
CATEGORIES=	cross
MASTER_SITES=	http://savannah.nongnu.org/download/avrdude/stable.pkg/4.1.0/

MAINTAINER=	karlj@mdstud.chalmers.se
HOMEPAGE=	http://www.bsdhome.com/avrdude/
COMMENT=	Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers

USE_GNU_READLINE=	YES

BUILD_DEPENDS+=	teTeX>=1.0:../../print/teTeX
BUILD_DEPENDS+=	texi2html>=1.76:../../textproc/texi2html

GNU_CONFIGURE=	yes
INFO_FILES=	avrdude.info
USE_MAKEINFO=	yes

CONFIGURE_ARGS=	--disable-versioned-doc

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
