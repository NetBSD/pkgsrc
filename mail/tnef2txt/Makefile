# $NetBSD: Makefile,v 1.8 2008/03/04 17:57:20 jlam Exp $
#

DISTNAME=	tnef2txt-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.fiction.net/blong/programs/tnef2txt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fiction.net/blong/programs/
COMMENT=	Portable application/ms-tnef parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	tnef2txt

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tnef2txt ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
