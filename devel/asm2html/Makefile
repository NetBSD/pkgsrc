# $NetBSD: Makefile,v 1.3 2003/01/23 16:12:02 jmmv Exp $
#

DISTNAME=	asm2html-1.3
CATEGORIES=	devel
MASTER_SITES=	http://virtus.ath.cx/asm2html/ \
		http://asm2html.kerneled.com/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://virtus.ath.cx/asm2html/
COMMENT=	Tool to convert NASM source files to HTML

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asm2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
