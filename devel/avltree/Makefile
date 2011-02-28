# $NetBSD: Makefile,v 1.10 2011/02/28 14:52:44 wiz Exp $

DISTNAME=	avltree-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://odin.compchem.ucsf.edu/pub/amber/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	In-memory index w/ binary and string keys and key counts

PKG_DESTDIR_SUPPORT=	user-destdir

MANCOMPRESSED_IF_MANZ=	yes
INSTALL_TARGET=	includes install
MAKE_ENV+=	${BSD_MAKE_ENV}

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

post-extract:
	cp -f ${FILESDIR}/Makefile ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
