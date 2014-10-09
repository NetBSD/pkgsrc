# $NetBSD: Makefile,v 1.10 2014/10/09 14:06:41 wiz Exp $
#

DISTNAME=	tnef2txt-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fiction.net/blong/programs/
COMMENT=	Portable application/ms-tnef parser

BUILD_TARGET=	tnef2txt

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
