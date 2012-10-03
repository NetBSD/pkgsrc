# $NetBSD: Makefile,v 1.4 2012/10/03 18:28:29 asau Exp $
#

DISTNAME=	otf2bdf-3.1
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.math.nmsu.edu/~mleisher/Software/otf2bdf/
EXTRACT_SUFX=	.tbz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.math.nmsu.edu/~mleisher/Software/otf2bdf/
COMMENT=	OpenType to BDF font converter

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
EGFILES=	${EGFILES_CMD:sh}
EGFILES_CMD=	ls ${WRKSRC}/maps/*

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${EGFILES:@.f.@${INSTALL_DATA} ${.f.} ${DESTDIR}${EGDIR}${.newline}@}

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
