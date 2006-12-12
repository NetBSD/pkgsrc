# $NetBSD: Makefile,v 1.8 2006/12/12 14:44:18 joerg Exp $

DISTNAME=	avltree-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://odin.compchem.ucsf.edu/pub/amber/

MAINTAINER=	wrstuden@NetBSD.org
#HOMEPAGE=
COMMENT=	In-memory index w/ binary and string keys and key counts

MANCOMPRESSED_IF_MANZ=	yes
INSTALL_TARGET=	includes install
MAKE_ENV+=	${BSD_MAKE_ENV}

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

post-extract:
	cp -f ${FILESDIR}/Makefile ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
