# $NetBSD: Makefile,v 1.1.1.1 2003/01/13 22:06:42 jmmv Exp $
#

DISTNAME=	asm2html-1.0
CATEGORIES=	devel
MASTER_SITES=	http://virtus.ath.cx/asm2html/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://virtus.ath.cx/asm2html/
COMMENT=	Tool to convert NASM source files to HTML

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asm2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
