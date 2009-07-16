# $NetBSD: Makefile,v 1.13 2009/07/16 16:12:47 jakllsch Exp $
#

DISTNAME=	cuetools-1.3.1
CATEGORIES=	misc
MASTER_SITES=	http://download.berlios.de/cuetools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cuetools.berlios.de/
COMMENT=	Set of utilities to manipulate cue and toc files
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	share/doc/cuetools

post-install:
	${INSTALL_DATA} ${WRKSRC}/extras/formats.txt \
		${DESTDIR}${PREFIX}/share/doc/cuetools/

.include "../../mk/bsd.pkg.mk"
