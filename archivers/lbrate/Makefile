# $NetBSD: Makefile,v 1.9 2005/12/01 16:41:29 rillig Exp $

DISTNAME=	lbrate-1.1
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/utils/compress/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/lbrate.html
COMMENT=	Extract/decompress CP/M LBR archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
LBRATE_DOCSDIR=	${PREFIX}/share/doc/lbrate

post-install:
	@${INSTALL_DATA_DIR} ${LBRATE_DOCSDIR}
	for f in COPYING ChangeLog README TODO; do		\
	${INSTALL_DATA} ${WRKSRC}/$$f ${LBRATE_DOCSDIR}; done

.include "../../mk/bsd.pkg.mk"
