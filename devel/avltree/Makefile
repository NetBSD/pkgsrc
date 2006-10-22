# $NetBSD: Makefile,v 1.7 2006/10/22 07:12:14 rillig Exp $

DISTNAME=	avltree-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://odin.compchem.ucsf.edu/pub/amber/

MAINTAINER=	wrstuden@NetBSD.org
#HOMEPAGE=
COMMENT=	In-memory index w/ binary and string keys and key counts

MANCOMPRESSED_IF_MANZ=	yes
INSTALL_TARGET=	includes install
MAKE_ENV+=	${BSD_MAKE_ENV}

INSTALLATION_DIRS=	${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

post-extract:
	cp -f ${FILESDIR}/Makefile ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
