# $NetBSD: Makefile,v 1.5 2004/05/10 23:20:30 minskim Exp $
#

DISTNAME=	tnef2txt-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fiction.net/blong/programs/
COMMENT=	Portable application/ms-tnef parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ALL_TARGET=	tnef2txt

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
