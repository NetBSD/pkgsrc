# $NetBSD: Makefile,v 1.3 2003/07/17 21:47:09 grant Exp $
#

DISTNAME=	tnef2txt-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fiction.net/blong/programs/
COMMENT=	portable application/ms-tnef parser

ALL_TARGET=	tnef2txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
