# $NetBSD: Makefile,v 1.9 2012/10/08 12:19:34 asau Exp $
#

DISTNAME=	tnef2txt-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fiction.net/blong/programs/
COMMENT=	Portable application/ms-tnef parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=	tnef2txt

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
