# $NetBSD: Makefile,v 1.1.1.1 2004/06/05 21:42:36 reed Exp $
#

DISTNAME=		pine-pgp-filters-1.1
CATEGORIES=		security mail
MASTER_SITES=		http://dougbarton.net/FreeBSD/Downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://dougbarton.net/FreeBSD/Downloads/
COMMENT=		Filters to integrate Pine with gnupg or pgp

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
NO_BUILD=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pine-pgp-filters
.for f in BUGS CHANGES INSTALL LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/pine-pgp-filters/
.endfor

.include "../../mk/bsd.pkg.mk"
