# $NetBSD: Makefile,v 1.10 2005/11/11 18:50:24 tonio Exp $

DISTNAME=	avrdude-4.1.0
PKGREVISION=	2
CATEGORIES=	cross
MASTER_SITES=	http://savannah.nongnu.org/download/avrdude/stable.pkg/4.1.0/

MAINTAINER=	karlj@mdstud.chalmers.se
HOMEPAGE=	http://www.bsdhome.com/avrdude/
COMMENT=	Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers

USE_GNU_READLINE=	YES
TEX_DEPMETHOD=	build
TEX_ACCEPTED=		teTeX1 teTeX2 teTeX3

BUILD_DEPENDS+=	texi2html>=1.76:../../textproc/texi2html

GNU_CONFIGURE=	yes
INFO_FILES=	avrdude.info
USE_MAKEINFO=	yes

CONFIGURE_ARGS=	--disable-versioned-doc

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
