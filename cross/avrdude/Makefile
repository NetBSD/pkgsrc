# $NetBSD: Makefile,v 1.14 2006/03/22 18:41:09 jlam Exp $

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

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo texi2html
INFO_FILES=	# PLIST

CONFIGURE_ARGS+=	--disable-versioned-doc

# Remove avrdude's buggy and outdated texinfo.tex that was breaking
# modern etex.
#
post-extract:
	${RM} -f ${WRKSRC}/doc/texinfo.tex

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
