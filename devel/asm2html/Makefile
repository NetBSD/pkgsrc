# $NetBSD: Makefile,v 1.2 2003/01/19 09:11:49 jmmv Exp $
#

DISTNAME=	asm2html-1.2
CATEGORIES=	devel
MASTER_SITES=	http://virtus.ath.cx/asm2html/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://virtus.ath.cx/asm2html/
COMMENT=	Tool to convert NASM source files to HTML

USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asm2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
