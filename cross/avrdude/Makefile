# $NetBSD: Makefile,v 1.13 2006/03/05 16:27:23 jlam Exp $

DISTNAME=	avrdude-4.1.0
PKGREVISION=	3
CATEGORIES=	cross
MASTER_SITES=	http://savannah.nongnu.org/download/avrdude/stable.pkg/4.1.0/

MAINTAINER=	karlj@mdstud.chalmers.se
HOMEPAGE=	http://www.bsdhome.com/avrdude/
COMMENT=	Downloader/uploader for Atmel AVR 8-bit RISC microcontrollers

USE_GNU_READLINE=	YES
TEX_DEPMETHOD=		build
TEX_ACCEPTED=		teTeX1 teTeX2 teTeX3

BUILD_DEPENDS+=	texi2html>=1.76:../../textproc/texi2html

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	avrdude.info

CONFIGURE_ARGS+=	--disable-versioned-doc

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
