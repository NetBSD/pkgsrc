# $NetBSD: Makefile,v 1.6 2023/12/23 08:50:33 zafer Exp $

DISTNAME=	Symbola
PKGNAME=	symbola-ttf-9.17
CATEGORIES=	fonts
MASTER_SITES=	#
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
