# $NetBSD: Makefile,v 1.1.1.1 2006/05/04 09:35:33 minskim Exp $

DISTNAME=	sgb
PKGNAME=	${DISTNAME}-0pre20050409
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.stanford.edu/pub/sgb/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www-cs-faculty.stanford.edu/~uno/sgb.html
COMMENT=	The Stanford GraphBase

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin

USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}

BUILD_TARGET=	lib doc
TEST_TARGET=	tests

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sgb
.for f in abstract.dvi README ERRATA
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/sgb
.endfor

.include "../../mk/bsd.pkg.mk"
