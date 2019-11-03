# $NetBSD: Makefile,v 1.14 2019/11/03 10:39:06 rillig Exp $

DISTNAME=	avltree-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://odin.compchem.ucsf.edu/pub/amber/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	In-memory index w/ binary and string keys and key counts

USE_TOOLS+=	nroff

MANCOMPRESSED_IF_MANZ=	yes
INSTALL_TARGET=		includes install
USE_BSD_MAKEFILE=	yes
MAKE_FLAGS+=		MKPROFILE=yes

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

post-extract:
	cp -f ${FILESDIR}/Makefile ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
