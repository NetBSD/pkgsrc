# $NetBSD: Makefile,v 1.5 2020/11/06 18:04:26 maya Exp $

DISTNAME=	Symbola
PKGNAME=	symbola-ttf-9.17
CATEGORIES=	fonts
MASTER_SITES=	http://users.teilar.gr/~g1951d/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.teilar.gr/~g1951d/
COMMENT=	Basic Latin, Greek, Cyrillic, and many Symbol blocks from Unicode
# Fonts in this site are offered free for any use; they may be
# installed, embedded, opened, edited, modified, regenerated, posted,
# packaged and redistributed.
LICENSE=	public-domain

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
