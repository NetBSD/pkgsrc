# $NetBSD: Makefile,v 1.1.1.1 2002/02/14 13:16:36 drochner Exp $
#

DISTNAME=	tnef2txt-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fiction.net/blong/programs/
COMMENT=	portable application/ms-tnef parser

ALL_TARGET=	tnef2txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
