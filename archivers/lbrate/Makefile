# $NetBSD: Makefile,v 1.7 2005/03/24 21:12:50 wiz Exp $

DISTNAME=	lbrate-1.1
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/utils/compress/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/lbrate.html
COMMENT=	Extract/decompress CP/M LBR archives

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
MAKE_FLAGS+=	PREFIX=${PREFIX}
LBRATE_DOCSDIR=	${PREFIX}/share/doc/lbrate

post-install:
	@${INSTALL_DATA_DIR} ${LBRATE_DOCSDIR}
	for f in COPYING ChangeLog README TODO; do		\
	${INSTALL_DATA} ${WRKSRC}/$$f ${LBRATE_DOCSDIR}; done

.include "../../mk/bsd.pkg.mk"
