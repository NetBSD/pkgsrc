# $NetBSD: Makefile,v 1.4 2003/07/21 16:56:57 martti Exp $
#

DISTNAME=	tnef2txt-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fiction.net/blong/programs/
COMMENT=	Portable application/ms-tnef parser

ALL_TARGET=	tnef2txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
