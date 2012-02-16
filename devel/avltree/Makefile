# $NetBSD: Makefile,v 1.12 2012/02/16 18:10:43 hans Exp $

DISTNAME=	avltree-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://odin.compchem.ucsf.edu/pub/amber/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	In-memory index w/ binary and string keys and key counts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	nroff

MANCOMPRESSED_IF_MANZ=	yes
INSTALL_TARGET=	includes install
USE_BSD_MAKEFILE=	yes
MAKE_FLAGS+=	MKPROFILE=yes

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

post-extract:
	cp -f ${FILESDIR}/Makefile ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
